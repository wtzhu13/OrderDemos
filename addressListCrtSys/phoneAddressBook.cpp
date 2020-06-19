#include "phoneAddressBook.h"

PhoneAddressBook::PhoneAddressBook(/* args */)
{
    this->contacesNum = 0;
    this->getContacesNum();
    contaceList = new PhoneContace*[this->contacesNum];
    this->initContacesList();
}

PhoneAddressBook::~PhoneAddressBook()
{
    delete[] this->contaceList;
}

/***
 * 将文件中的数据放到内存空间
 * */
void PhoneAddressBook::initContacesList()
{
    ifstream ifs;
    ifs.open("phoneList.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "打开phoneList.txt失败！" << endl;
    }
    // 定义临时变量存放文件中的参数
    string name;
    string phoneNum;
    string nativePlace;
    string QQNum;
    int i = 0;
    // 遍历文件，并创建新的手机联系人对象，并加入到数组中
    while (ifs >> name && ifs >> phoneNum 
            && ifs >> nativePlace && ifs >> QQNum)
    {
        PhoneContace *phoneContace = NULL;
        // 修改用户信息
        phoneContace = new PhoneContace();
        phoneContace->setInfo(name, phoneNum, nativePlace, QQNum);
        // 将用户放到数组中
        this->contaceList[i] = phoneContace;
        i++;
    }
    ifs.close();
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
    ifs.close();
}

/***
 * 新增一个联系人
 * */
void PhoneAddressBook::addUser()
{
    // 如果联系人达到1000则表明存储满了
    this->getContacesNum();
    // cout << this->contacesNum << endl;
    if (this->contacesNum >= 1000)
    {
        cout << "空间不足" << endl;
        return;
    }

    PhoneContace *phoneContace = NULL;
    phoneContace = new PhoneContace();
    cin >> *phoneContace;

    // 添加一个人后新的人数
    int newContacesNum = this->contacesNum + 1;
    // 开辟一块新的空间
    PhoneContace **newContaceList = new PhoneContace*[newContacesNum];
    
    // cout << *contaceList[0] << endl;
    //将原空间下内容存放到新空间下
    // cout << "ok0" << endl;
    for (int i = 0; i < this->contacesNum; i++)
    {
        newContaceList[i] = this->contaceList[i];
    }
    // cout << "ok1" << endl;
    // 将新增的用户放进数组
    newContaceList[newContacesNum] = phoneContace;
    // cout << "添加用户成功!!!" << endl;
    // 释放原有空间
    delete[] this->contaceList;
    this->contaceList = NULL;
    // 将新的地址更新到数组
    this->contaceList = newContaceList;
    // 释放新的空间
    delete[] newContaceList;
    newContaceList = NULL;
    // 用户数量增加
    this->contacesNum++;
    // cout << "ok" << endl;
    // 将信息存放到本地文件中
    ofstream ofs;
    ofs.open("phoneList.txt", ios::app);
    cout << "save" << endl;
    ofs << phoneContace->name << " " << phoneContace->phoneNum 
        << " " << phoneContace->nativePlace << " " << phoneContace->qqNum << endl;
    ofs.close();
    // this->saveToFile();
    cout << "添加用户成功！" << endl;

}

/***
 * 判断联系人是否存在
 * */
int PhoneAddressBook::isExist(string phoneNum)
{
    int index = -1;
    for (int i = 0; i < this->contacesNum; i++)
    {
        // 找到电话相同的就返回索引
        if (this->contaceList[i]->phoneNum == phoneNum)
        {
            index = i;
            break;
        }     
    }
    // 没有就直接返回0
    return index;
}

/***
 * 删除联系人
 * */
void PhoneAddressBook::delUser()
{
    string phoneNum;
    cout << "请输入号码：";
    cin >> phoneNum;
    int index = this->isExist(phoneNum);
    if (index != -1)
    {
        for (int i = index; i < this->contacesNum-1; i++)
        {
            this->contaceList[i] = this->contaceList[i+1];
        }   
        this->contacesNum--;
        this->saveToFile();
        cout << "删除成功" << endl;    
    }
    
}

/***
 * 保存到本地
 * */
void PhoneAddressBook::saveToFile()
{
    // cout << "save" << endl;
    ofstream ofs;
    ofs.open("phoneList.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "phoneList.txt打开失败" << endl;
        return;
    }
    
    for (int i = 0; i < this->contacesNum; i++)
    {
        ofs << this->contaceList[i]->name << " "
            << this->contaceList[i]->phoneNum << " "
            << this->contaceList[i]->nativePlace << " "
            << this->contaceList[i]->qqNum << endl;
    }
    ofs.close();
    // cout << "save end" << endl;

}

/***
 * 查看
 * */
void PhoneAddressBook::showAllUser()
{
    for (int i = 0; i < this->contacesNum; i++)
    {
        cout << *(this->contaceList[i]) << endl;
    }
}

/***
 * 修改
 * */
void PhoneAddressBook::modifyInfo(string phoneNum)
{
    
    int index = this->isExist(phoneNum);
    if (index == -1)
    {
        cout << "手机中不存在改联系人" << endl;
        return;
    }
    this->ui.showAddUserMenu(1);
    PhoneContace *phoneContace = NULL;
    phoneContace = new PhoneContace();
    cin >> *phoneContace;
    this->contaceList[index] = phoneContace;
    this->saveToFile();
    cout << "修改成功" << endl;
}

/***
 * 查询
 * */
void PhoneAddressBook::findUserInfo(string name)
{
    int flag = 0;
    // this->initContacesList();
    for (int i = 0; i < this->contacesNum; i++)
    {
        if (this->contaceList[i]->name == name)
        {
            flag = 1;
            cout << *(this->contaceList[i]) << endl;
        }      
    }
    if (!flag)
    {
        cout << "卡中不存在该联系人" << endl;
    }
}