#ifndef _MANAGE_H_
#define _MANAGE_H_

#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

void initSys();
void initList();
void getGoodsNum();
void addGood();


typedef struct Good
{
    char name[13];
    int price;
    int saleVolume;
}Good;

Good **goodList;
int goodsNum;
void saveDataToFile();
void showGoodList();
void delGood();
int isExit(char *goodName);
void sortGoodList();
void sortByPrice();
void sortBySaleVolume();
void findGoodByName();
void changeInfoByName();

#endif