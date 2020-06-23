/*******************************************
* 作者：wtzhu
* 说明：
* 日期：
* 邮箱：wtzhu_13@163.com
* 版本：
*      更多内容请关注https://blog.csdn.net/wtzhu_13
********************************************/
#include "ui.h"
#include "manage.h"

int main(int argc, char const *argv[])
{
    initSys();
    while (1)
    {
        showMainMenu();
        int mainChoice;
        printf("请选择功能编号：");
        scanf("%d", &mainChoice);
        switch (mainChoice)
        {
        case 1:
            showGoodList();
            break;
        case 2:
            addGood();
            break;
        case 3:
            delGood();
            break;
        case 4:
            sortByPrice();
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 0:
            free(goodList);
            return 0;
        default:
            break;
        }
    }  
    return 0;
}

