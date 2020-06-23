/*******************************************
* 作者：wtzhu
* 说明：
* 日期：
* 邮箱：wtzhu_13@163.com
* 版本：
*      更多内容请关注https://blog.csdn.net/wtzhu_13
********************************************/

#include "manage.h"

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void initSys()
{
    // 商品列表分配空间
    getGoodsNum();
    // 给goodlist分配空间
    goodList = (Good **)malloc(goodsNum * sizeof(Good *));
    // 初始化商品数组
    initList();
}

/*******************************************
* 函数名：
* 功能：初始化商品数组，
* 参数：
* 返回值：
********************************************/
void initList()
{
    FILE *fp;
    fp = fopen("goodList.txt", "r");
    if (fp == NULL)
    {
        printf("initList(): goodList.txt open err!\n");
    }
    int count = 0;
    
    while (!feof(fp))
    {    
        Good *goodFromTxtP = (Good *)malloc(sizeof(Good));  
        // 格式化读取文件内容，便于直接赋值
        int end = fscanf(fp, "%s %d %d", goodFromTxtP->name, &(goodFromTxtP->price), &(goodFromTxtP->saleVolume));
        // 防止最后一行读取两次
        if (end == EOF)
        {
            break;
        }      
        printf("%s %d %d\n", goodFromTxtP->name, goodFromTxtP->price, goodFromTxtP->saleVolume);
        // 将该指针赋值给数组中的指针
        // 这里不用释放goodFromTxtP指向的内存，因为释放了数组中的指针指向也释放了
        goodList[count] = goodFromTxtP;
          
        count++;
    }
    fclose(fp); 
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void getGoodsNum()
{
    // 打开文件
    FILE *fp;
    fp = fopen("goodList.txt", "r");
    // 判断文件是否代开失败
    if (fp == NULL)
    {
        printf("getGoodsNum(): goodList.txt open err!\n");
    }
    else
    {
        while (!feof(fp))
        {
            // 遇到一个换行符就说明有一行
            int flag = fgetc(fp);
            if(flag == '\n')
                goodsNum++;
        }    
    }
    // 关闭文件
    fclose(fp);
    printf("goodsNum: %d\n", goodsNum);
}

/*******************************************
* 函数名：
* 功能：显示商品列表
* 参数：
* 返回值：
********************************************/
void showGoodList()
{
    // 遍历商品列表并打印
    printf("商品列表：\n");
    for (int i = 0; i < goodsNum; i++)
    {
        printf("name:%s price:%d saleVolume:%d \n",
         goodList[i]->name, goodList[i]->price, goodList[i]->saleVolume);
    }   
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void addGood()
{
    // 获取数据库中已存在的商品量
    showAddGoodMenu(); 

    // 定义临时变量接受用户的输入
    Good *goodAdd = (Good *)malloc(sizeof(Good));
    scanf("%s %d %d", goodAdd->name, &goodAdd->price, &goodAdd->saleVolume);  
    printf("name:%s price:%d saleVolume:%d 添加成功！\n", goodAdd->name, goodAdd->price, goodAdd->saleVolume);

    // 定义一个新的数组比这个大一个数据类型用于存放新增的数据
    int newGoodNum = goodsNum + 1;
    Good **newGoodList = malloc(newGoodNum * sizeof(Good *));

    for (int i = 0; i < goodsNum; i++)
    {
        newGoodList[i] = goodList[i];
    }
    // 新增的数据放进数组中
    newGoodList[goodsNum] = goodAdd;
    
    // 把旧的空间释放
    free(goodList);
    
    // 把新的数组地址给原数组
    goodList = newGoodList;
    goodsNum = newGoodNum;
    newGoodList = NULL;

    // 把新增的商品写进文件中
    saveDataToFile();
}

/*******************************************
* 函数名：
* 功能：保存数据到文件中
* 参数：
* 返回值：
********************************************/
void saveDataToFile()
{
    FILE *fp;
    fp = fopen("goodList.txt", "w");
    if (fp == NULL)
    {
        printf("saveDataToFile(): goodList.txt open err!");
        return;
    }
    // 遍历商品列表，将数据写进文件
    for (int i = 0; i < goodsNum; i++)
    {
        printf("%s %d %d\n", goodList[i]->name, goodList[i]->price, goodList[i]->saleVolume);
        fprintf(fp, "%s %d %d\n", goodList[i]->name, goodList[i]->price, goodList[i]->saleVolume);
    }
    fclose(fp);
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void delGood()
{
    // 获取待删除的商品的名称
    char delGoodName[13];
    showDelGoodMenu();
    scanf("%s", delGoodName);

    // 判断该商品是否存在
    int index = isExit(delGoodName);
    if (index == -1)
    {
        printf("该商品不存在\n");
        return;
    }
    // 把找到的商品后面的商品前移一位完成删除
    for (size_t i = index; i < goodsNum-1; i++)
    {
        goodList[i] = goodList[i + 1];
    }
    // 保存到文件
    saveDataToFile();   
}

/*******************************************
* 函数名：
* 功能：判断某个商品是否存在
* 参数：
* 返回值：存在返回该商品的索引，否则返回-1
********************************************/
int isExit(char *goodName)
{
    // 遍历数组，查找是否有同名的
    for (int i = 0; i < goodsNum; i++)
    {
        if (strcmp(goodName, goodList[i]->name) == 0)
        {
            return i;
        }       
    }
    return -1;
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void sortGoodList()
{
    showSortMenu();
    int sortChoice;
    scanf("%d", &sortChoice);
    switch (sortChoice)
    {
    case 1:
        sortByPrice();
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    default:
        break;
    }
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void sortByPrice()
{
    for (int i = 0; i < goodsNum-1; i++)
    {
        for (size_t j = i+1; i < goodsNum; i++)
        {
            if (goodList[i]->price > goodList[j]->price)
            {
                Good *goodTmp;
                goodTmp = goodList[i];
                goodList[i] = goodList[j];
                goodTmp = NULL;
            }           
        }        
    }
    showGoodList();
}