#include "user.h"
#include "ui.h"

User::User(/* args */)
{
}

User::~User()
{
}

/**
 * 添加用户
*/
void User::addUser()
{
    // 显示主菜单
    ui.showAddUserMenu(1);
    int choiceSaveAdd;
    cin >> choiceSaveAdd;
    // 显示输入信息菜单
    ui.showAddUserMenu(2);
    string name;
    string nativePlace;
    string phoneNum;
    string qqNum;
    cin >> name >> nativePlace >> phoneNum >> qqNum;
}