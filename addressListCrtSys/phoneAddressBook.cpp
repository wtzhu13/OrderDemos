#include "phoneAddressBook.h"

PhoneAddressBook::PhoneAddressBook(/* args */)
{
    this->contacesNum = 0;
    this->getContacesNum();
    contaceList = new PhoneContace[this->contacesNum];
}

PhoneAddressBook::~PhoneAddressBook()
{
    delete contaceList;
}

/***
 * ��ȡ��ϵ������
 * */
void PhoneAddressBook::getContacesNum()
{
    // �����ֻ�ͨѶ¼�ļ�
    ifstream ifs;
    ifs.open("phoneList.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "phoneList.txt��ʧ�ܣ�" << endl;
    }
    string buf;
    // ��һ�У���ô��˵���и���ϵ�ˣ�������һ
    while (getline(ifs, buf))
    {
        this->contacesNum++;
    } 
}

/***
 * ����һ����ϵ��
 * */
void PhoneAddressBook::addUser()
{

}

void PhoneAddressBook::delUser()
{

}

void PhoneAddressBook::showAllUser()
{

}

void PhoneAddressBook::modifyInfo()
{

}

void PhoneAddressBook::findUserInfo()
{

}