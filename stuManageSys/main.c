/*******************************************
* 作者：wtzhu
* 说明：
* 日期：
* 邮箱：wtzhu_13@163.com
* 版本：
*      更多内容请关注https://blog.csdn.net/wtzhu_13
********************************************/
#include "ui.h"
#include "global.h"
#include "manage.h"

int main(int argc, char const *argv[])
{
    initSys();
    while (1)
    {
        showMainMenu();
        int mainChoice;
        scanf("%d", &mainChoice);
        switch (mainChoice)
        {
            case 1:
                addStuInfo();
                break;
            case 2:
                delStuInfo();
                break;
            case 3:
                modifyStuInfo();
                break;
            case 4:
                showAllInfo();
                break;
            case 5:
                showPointCourseGrade();
                break;
            case 6:
                showAllStuGrade();
                break;
            case 7:
                showPointStuGrade();
                break;
            case 8:
                GradeAnalyse();
                break;
            case 0:
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}
