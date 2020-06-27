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
    stuNum = 10;
    stuList = (Stu*)malloc(stuNum * sizeof(Stu));
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
    Stu stuTemp;
    scanf("%s %s %d %c %d %d %d", 
    stuTemp.id, stuTemp.name, &stuTemp.class, &stuTemp.sex,
    &stuTemp.Math, &stuTemp.Chinese, &stuTemp.English);
    printf("%s %s %d %c %d %d %d\n", 
    stuTemp.id, stuTemp.name, stuTemp.class, stuTemp.sex,
    stuTemp.Math, stuTemp.Chinese, stuTemp.English);
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
        fprintf(fp, "%s,%s,%d,%c,%d,%d,%d\n", 
        stuList[i].id, stuList[i].name, stuList[i].class,stuList[i].sex,
        stuList[i].Math, stuList[i].Chinese, stuList[i].English);
    }
    // 关闭文件
    fclose(fp);
}
