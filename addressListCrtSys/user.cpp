#include "user.h"
#include "ui.h"

User::User(/* args */)
{
}

User::~User()
{
}

/**
 * 新增用户
*/
void User::addUser()
{
    // 显示菜单
    ui.showAddUserMenu(0);
    int choiceSaveAdd;
    cin >> choiceSaveAdd;
    // 显示存储方式菜单
    ui.showAddUserMenu(choiceSaveAdd);
    // 利用多肽实现调用
    switch (choiceSaveAdd)
    {
    case 1:
        this->saveUser(this->pab);
        break;
    case 2:
        this->saveUser(this->pcab);
        break;
    default:
        break;
    }
}

/**
 * 保存用户信息
*/
void User::saveUser(AddressBook &adb)
{
    adb.addUser();
}