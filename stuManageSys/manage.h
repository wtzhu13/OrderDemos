/*******************************************
* 作者：wtzhu
* 说明：
* 日期：
* 邮箱：wtzhu_13@163.com
* 版本：
********************************************/
#ifndef _MANAGE_H_
#define _MANAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "global.h"

Stu *stuList;
int stuNum;

void addStuInfo();
void initSys();
void saveToFile();

#endif