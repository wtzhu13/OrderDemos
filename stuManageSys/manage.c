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
    getStuNum();
    stuList = (Stu*)malloc(stuNum * sizeof(Stu));
    initList();
}

/*******************************************
* 函数名：
* 功能：获取学生人数
* 参数：
* 返回值：
********************************************/
void getStuNum()
{
    FILE *fp;
    fp = fopen("stuInfo.txt", "r");
    if (fp == NULL)
    {
        printf("getStuNum(): stuInfo.tx opened err");
        return;
    }
    while (!feof(fp))
    {
        int flag = fgetc(fp);
        // 遇到换行符就是一行，就说明学生数据多一个
        if(flag == '\n')
            stuNum++;
    }
    fclose(fp);
}

/*******************************************
* 函数名：
* 功能：初始化学生数据数组
* 参数：
* 返回值：
********************************************/
void initList()
{
    int count = 0;
    // 打开文件
    FILE *fp;
    fp = fopen("stuInfo.txt", "r");
    if (fp == NULL)
    {
        printf("initList(): stuInfo.tx opened err");
        return;
    }
    while (!feof(fp))
    { 
        // 格式化获取文件中的内容,注意格式和scanf一样，后面跟的是指针
        int end = fscanf(fp, "%s %s %d %c %d %d %d",
        stuList[count].id, stuList[count].name, &stuList[count].class, &stuList[count].sex,
        &stuList[count].Math, &stuList[count].Chinese, &stuList[count].English);
        // 防止最后一行读取两遍
        if (end == EOF)
        {
            break;
        }
        count++;
    }
    // 关闭文件指针
    fclose(fp);
}

/*******************************************
* 函数名：
* 功能：添加学生信息
* 参数：
* 返回值：
********************************************/
void addStuInfo()
{
    showAddMenu();
    // 获取用户输入的信息
    Stu stuTemp;
    scanf("%s %s %d %c %d %d %d", 
    stuTemp.id, stuTemp.name, &stuTemp.class, &stuTemp.sex,
    &stuTemp.Math, &stuTemp.Chinese, &stuTemp.English);

    // 新建一个数组，容量加一
    int newStuNum = stuNum + 1;
    Stu *newStuList = (Stu*)malloc(newStuNum * sizeof(Stu));

    // 把之前的信息拷贝到新的地址并把新增的也加进去
    for (int i = 0; i < stuNum; i++)
    {
        newStuList[i] = stuList[i];
    }
    newStuList[stuNum] = stuTemp;

    // 更新数组
    if (stuList != NULL)
    {
        free(stuList);
        stuList = NULL;
    }
    stuList = newStuList;
    stuNum = newStuNum;
    newStuList = NULL;
    
    saveToFile();
    waitPress();
}

/*******************************************
* 函数名：
* 功能：将信息保存到本地文件中
* 参数：
* 返回值：
********************************************/
void saveToFile()
{
    FILE *fp;
    // 以写的方式打开信息文件
    fp = fopen("stuInfo.txt", "w");
    if (fp == NULL)
    {
        printf("saveToFile():stuInfo.txt opened err!\n");
        return;
    }
    // 循环遍历数组将信息保存到本地文件
    for (int i = 0; i < stuNum; i++)
    {
        fprintf(fp, "%s %s %d %c %d %d %d\n", 
        stuList[i].id, stuList[i].name, stuList[i].class, stuList[i].sex,
        stuList[i].Math, stuList[i].Chinese, stuList[i].English);

        // printf("%s,%s,%d,%c,%d,%d,%d\n", 
        // stuList[i].id, stuList[i].name, stuList[i].class, stuList[i].sex,
        // stuList[i].Math, stuList[i].Chinese, stuList[i].English);
    }
    // 关闭文件
    fclose(fp);
}

/*******************************************
* 函数名：
* 功能：显示所有人的信息
* 参数：
* 返回值：
********************************************/
void showAllInfo()
{
    system(CLEAR);
    for (int i = 0; i < stuNum; i++)
    {
        printf("学号：%s,姓名：%s,班级号：%d,性别：%c,数学成绩：%d,语文成绩：%d,英语成绩：%d\n", 
        stuList[i].id, stuList[i].name, stuList[i].class, stuList[i].sex,
        stuList[i].Math, stuList[i].Chinese, stuList[i].English);
    }
#if Windows   
    system("pause");
#else 
    waitPress();
#endif
}

/*******************************************
* 函数名：
* 功能：删除学生信息
* 参数：
* 返回值：
********************************************/
void delStuInfo()
{
    // 获取需要删除的学生的学号
    char idFound[13];
    printf("请输入需要删除的学生的学号：\n");
    scanf("%s", idFound);
    // 找到该学生
    int indexFound = isExist(idFound);
    if (indexFound == -1)
    {
        printf("该学生不存在！\n");
        return;
    }
    // 找到之后就把数组这个索引后面的数据前移
    for (int i = indexFound; i < stuNum-1; i++)
    {
        stuList[i] = stuList[i+1];
    }
    // 总得数据减一
    stuNum--;
}

/*******************************************
* 函数名：
* 功能：判断学生是否存在
* 参数：
* 返回值：存在返回索引，不存在返回-1
********************************************/
int isExist(char *idFound)
{
    // 遍历数组，当ID一致就返回索引
    for (int i = 0; i < stuNum; i++)
    {
        if (strcmp(stuList[i].id, idFound) == 0)
        {
            return i;
        }     
    }
    // 遍历完了，还没返回说明没有，则直接返回-1
    return -1;
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void modifyStuInfo()
{

}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void showPointCourseGrade()
{

}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void showAllStuGrade()
{

}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void showPointStuGrade()
{

}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void GradeAnalyse()
{

}