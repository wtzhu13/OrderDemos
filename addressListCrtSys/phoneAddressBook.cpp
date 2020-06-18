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
 * 获取联系人数量
 * */
void PhoneAddressBook::getContacesNum()
{
    // 便利手机通讯录文件
    ifstream ifs;
    ifs.open("phoneList.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "phoneList.txt打开失败！" << endl;
    }
    string buf;
    // 读一行，那么就说明有个联系人，数量加一
    while (getline(ifs, buf))
    {
        this->contacesNum++;
    } 
}

/***
 * 新增一个联系人
 * */
void PhoneAddressBook::addUser()
{
    // 如果联系人达到1000则表明存储满了
    this->getContacesNum();
    if (this->contacesNum >= 1000)
    {
        cout << "空间不足" << endl;
        return;
    }
    PhoneContace phoneContace;
    cin >> phoneContace;
    cout << phoneContace << endl;
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