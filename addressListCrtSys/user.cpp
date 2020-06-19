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

/**
 * 删除联系人
*/
void User::delContase()
{
    pab.delUser();
}

/**
 * 查询联系人
*/
void User::findContase()
{
    pab.findUserInfo();
}

/**
 * 修改联系人信息
*/
void User::modifyInfo()
{
    pab.modifyInfo();
}

/**
 * 显示所有联系人
*/
void User::showAllContaces()
{
    pcab.initContacesList();
    pab.initContacesList();
    // 先遍历手机中的
    for (int i = 0; i < pab.contacesNum; i++)
    {
        cout << *(pab.contaceList[i]) << endl;
    }
    // 遍历卡里的,且只打印手机中没有的
    for (int j = 0; j < pcab.contacesNum; j++)
    {
        int flag = 0;
        for (int i = 0; i < pab.contacesNum; i++)
        {
            if (pab.contaceList[i]->phoneNum == pcab.contaceList[j]->phoneNum)
            {
                flag = 1;
                break;
            }
        } 
        if (!flag)
        {
            cout << *(pcab.contaceList[j]) << endl;  
        }   
    }    
}

/**
 * 从手机保存到卡
*/
void User::fromPhoneToCard()
{
    pcab.initContacesList();
    pab.initContacesList();
    for (int i = 0; i < pab.contacesNum; i++)
    {
        int flag = 0;
        for (int j = 0; j < pcab.contacesNum; j++)
        {
            if (pab.contaceList[i]->phoneNum == pcab.contaceList[j]->phoneNum)
            {
                flag = 1;
                break;
            }
                       
        } 
        if (!flag)
        {
            ofstream ofs;
            ofs.open("cardList.txt", ios::app);
            ofs << pab.contaceList[i]->name << " " << pab.contaceList[i]->phoneNum << endl;
            ofs.close();
        }  
    }
    cout << "导出成功" << endl;
}

/**
 * 从卡保存到手机
*/
void User::fromCardToPhone()
{

}

