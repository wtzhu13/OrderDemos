#include "user.h"
#include "ui.h"

User::User(/* args */)
{
}

User::~User()
{
}

/**
 * �����û�
*/
void User::addUser()
{
    // ��ʾ�˵�
    ui.showAddUserMenu(0);
    int choiceSaveAdd;
    cin >> choiceSaveAdd;
    // ��ʾ�洢��ʽ�˵�
    ui.showAddUserMenu(choiceSaveAdd);
    // ���ö���ʵ�ֵ���
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
 * �����û���Ϣ
*/
void User::saveUser(AddressBook &adb)
{
    adb.addUser();
}