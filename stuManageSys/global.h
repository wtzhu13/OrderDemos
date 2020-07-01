/*******************************************
* 作者：wtzhu
* 说明：
* 日期：
* 邮箱：wtzhu_13@163.com
* 版本：
********************************************/
#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Windows 1

#if Windows
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

typedef struct Student
{
    char id[10];
    char name[13];
    int class;
    char sex;
    int Math;
    int Chinese;
    int English;
}Stu;

void waitPress();

#endif