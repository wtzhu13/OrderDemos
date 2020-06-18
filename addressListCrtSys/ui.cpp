#include "ui.h"

Ui::Ui(/* args */)
{
}

Ui::~Ui()
{
}

/**
 * 显示主菜单
*/
void Ui::showMainMenu()
{
    cout << "系统功能：" << endl;
    cout << "1.新建联系人" << endl;
    cout << "2.删除联系人" << endl;
    cout << "3.修改信息" << endl;
    cout << "4.查询" << endl;
    cout << "5.浏览" << endl;
    cout << "6.从手机复制到卡" << endl;
    cout << "7.从卡复制到手机" << endl;
    cout << "请选择功能序号：";
}

/**
 * 显示添加用户菜单
*/
void Ui::showAddUserMenu(int i)
{
    switch (i)
    {
    case 1:
        cout << "请选择存储方式：" << endl;
        cout << "1.手机存储" << endl;
        cout << "2.手机卡存储" << endl;
        cout << "请选择存储方式编号：";
        break;
    case 2:
        cout << "请输入联系人信息：" << endl;
        cout << "格式：姓名 籍贯 电话号码 QQ，中间空格隔开 " << endl;
        cout << "如：Tom Beijing 13511112222 123456987" << endl;
        cout << "请输入信息：";
        break;
    default:
        break;
    }
}