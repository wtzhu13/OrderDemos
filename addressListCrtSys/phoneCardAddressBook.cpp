#include "phoneCardAddressBook.h"

PhoneCardAddressBook::PhoneCardAddressBook(/* args */)
{
    this->contacesNum = 0;
    this->getContacesNum();
    contaceList = new PhoneCardContace*[this->contacesNum];
    this->initContacesList();
}

PhoneCardAddressBook::~PhoneCardAddressBook()
{
    delete[] this->contaceList;
}

/***
 * 初始化用户列表
 * */
void PhoneCardAddressBook::initContacesList()
{
    ifstream ifs;
    ifs.open("cardList.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "phoneList.txt打开失败" << endl;
    }
    // 临时变量存放文件内容
    string name;
    string phoneNum;
    int i = 0;
    // 遍历文件
    while (ifs >> name && ifs >> phoneNum )
    {
        PhoneCardContace *phoneCardContace = NULL;
        phoneCardContace = new PhoneCardContace();
        phoneCardContace->setInfo(name, phoneNum);
        // 把文件内容添加到列表
        this->contaceList[i] = phoneCardContace;
        i++;
    }
    ifs.close();
}

/***
 * 获取联系人数量
 * */
void PhoneCardAddressBook::getContacesNum()
{
    // 遍历文件
    ifstream ifs;
    ifs.open("cardList.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "cardList.txt打开失败" << endl;
    }
    string buf;
    // 遍历文件，记录行数
    while (getline(ifs, buf))
    {
        this->contacesNum++;
    } 
    ifs.close();
}

/***
 * 添加用户
 * */
void PhoneCardAddressBook::addUser()
{
    // 首先获取用户数量
    this->getContacesNum();
    // cout << this->contacesNum << endl;
    if (this->contacesNum >= 1000)
    {
        cout << "空间不足" << endl;
        return;
    }

    PhoneCardContace *phoneCardContace = NULL;
    phoneCardContace = new PhoneCardContace();
    cin >> *phoneCardContace;

    // 用户数量加一
    int newContacesNum = this->contacesNum + 1;
    // 新建一个临时存放
    PhoneCardContace **newContaceList = new PhoneCardContace*[newContacesNum];
    
    cout << *contaceList[0] << endl;
    // 将旧数据拷贝到新空间
    
    for (int i = 0; i < this->contacesNum; i++)
    {
        newContaceList[i] = this->contaceList[i];
    }

    // 经新增用户放进数组
    newContaceList[newContacesNum] = phoneCardContace;
    // cout << "娣诲姞鐢ㄦ埛鎴愬姛!!!" << endl;
    // 释放原有空间
    delete[] this->contaceList;
    // 将新的地址给列表指针
    this->contaceList = newContaceList;
    // 释放新空间
    delete[] newContaceList;
    // 用户数加一
    this->contacesNum++;

    // 将信息保存到本地
    ofstream ofs;
    ofs.open("cardList.txt", ios::app);
    ofs << phoneCardContace->name << " " << phoneCardContace->phoneNum << endl;
    ofs.close();
    cout << "添加用户成功" << endl;

}

void PhoneCardAddressBook::delUser()
{

}

void PhoneCardAddressBook::showAllUser()
{

}

void PhoneCardAddressBook::modifyInfo()
{

}

void PhoneCardAddressBook::findUserInfo()
{
    
}
