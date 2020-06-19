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

/**
 * ɾ����ϵ��
*/
void User::delContase()
{
    pab.delUser();
}

/**
 * ��ѯ��ϵ��
*/
void User::findContase()
{
    pab.findUserInfo();
}

/**
 * �޸���ϵ����Ϣ
*/
void User::modifyInfo()
{
    pab.modifyInfo();
}

/**
 * ��ʾ������ϵ��
*/
void User::showAllContaces()
{
    pcab.initContacesList();
    pab.initContacesList();
    // �ȱ����ֻ��е�
    for (int i = 0; i < pab.contacesNum; i++)
    {
        cout << *(pab.contaceList[i]) << endl;
    }
    // ���������,��ֻ��ӡ�ֻ���û�е�
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
 * ���ֻ����浽��
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
    cout << "�����ɹ�" << endl;
}

/**
 * �ӿ����浽�ֻ�
*/
void User::fromCardToPhone()
{

}

