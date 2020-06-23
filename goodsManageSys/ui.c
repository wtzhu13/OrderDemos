/*******************************************
* 作者：wtzhu
* 说明：
* 日期：
* 邮箱：wtzhu_13@163.com
* 版本：
*
*      更多内容请关注https://blog.csdn.net/wtzhu_13
*
********************************************/
#include "ui.h"
#include "global.h"

/*******************************************
* 函数名：
* 功能：显示主菜单功能
* 参数：
* 返回值：
********************************************/
void showMainMenu()
{
    printf("功能列表：\n");
    printf("1.显示商品列表\n");
    printf("2.添加商品\n");
    printf("3.删除商品\n");
    printf("4.排序商品列表\n");
    printf("5.查询商品\n");
    printf("6.更改商品信息\n");
    printf("0.退出\n");
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void showAddGoodMenu()
{
    // system(CLEAR);
    printf("商品信息格式如下：\n");
    printf("商品名称 单价 销量： 牛奶 60 300\n");
    printf("请输入商品信息：");
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void showDelGoodMenu()
{
    printf("请输入需要删除的商品的名称：");
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void showSortMenu()
{
    printf("排序方式:\n");
    printf("1.按售价排序\n");
    printf("2.按销量排序\n");
    printf("2.按商品名排序\n");
    printf("请输入排序方式编号:\n");
}