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
 * ���ļ��е����ݷŵ��ڴ�ռ�
 * */
void PhoneAddressBook::initContacesList()
{
    ifstream ifs;
    ifs.open("phoneList.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "��phoneList.txtʧ�ܣ�" << endl;
    }
    // ������ʱ��������ļ��еĲ���
    string name;
    string phoneNum;
    string nativePlace;
    string QQNum;
    int i = 0;
    // �����ļ����������µ��ֻ���ϵ�˶��󣬲����뵽������
    while (ifs >> name && ifs >> phoneNum 
            && ifs >> nativePlace && ifs >> QQNum)
    {
        PhoneContace *phoneContace = NULL;
        // �޸��û���Ϣ
        phoneContace = new PhoneContace();
        phoneContace->setInfo(name, phoneNum, nativePlace, QQNum);
        // ���û��ŵ�������
        this->contaceList[i] = phoneContace;
        i++;
    }
    ifs.close();
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
    ifs.close();
}

/***
 * ����һ����ϵ��
 * */
void PhoneAddressBook::addUser()
{
    // �����ϵ�˴ﵽ1000������洢����
    this->getContacesNum();
    // cout << this->contacesNum << endl;
    if (this->contacesNum >= 1000)
    {
        cout << "�ռ䲻��" << endl;
        return;
    }

    PhoneContace *phoneContace = NULL;
    phoneContace = new PhoneContace();
    cin >> *phoneContace;

    // ���һ���˺��µ�����
    int newContacesNum = this->contacesNum + 1;
    // ����һ���µĿռ�
    PhoneContace **newContaceList = new PhoneContace*[newContacesNum];
    
    // cout << *contaceList[0] << endl;
    //��ԭ�ռ������ݴ�ŵ��¿ռ���
    // cout << "ok0" << endl;
    for (int i = 0; i < this->contacesNum; i++)
    {
        newContaceList[i] = this->contaceList[i];
    }
    // cout << "ok1" << endl;
    // ���������û��Ž�����
    newContaceList[newContacesNum] = phoneContace;
    // cout << "����û��ɹ�!!!" << endl;
    // �ͷ�ԭ�пռ�
    delete[] this->contaceList;
    this->contaceList = NULL;
    // ���µĵ�ַ���µ�����
    this->contaceList = newContaceList;
    // �ͷ��µĿռ�
    delete[] newContaceList;
    newContaceList = NULL;
    // �û���������
    this->contacesNum++;
    // cout << "ok" << endl;
    // ����Ϣ��ŵ������ļ���
    ofstream ofs;
    ofs.open("phoneList.txt", ios::app);
    cout << "save" << endl;
    ofs << phoneContace->name << " " << phoneContace->phoneNum 
        << " " << phoneContace->nativePlace << " " << phoneContace->qqNum << endl;
    ofs.close();
    // this->saveToFile();
    cout << "����û��ɹ���" << endl;

}

/***
 * �ж���ϵ���Ƿ����
 * */
int PhoneAddressBook::isExist(string phoneNum)
{
    int index = -1;
    for (int i = 0; i < this->contacesNum; i++)
    {
        // �ҵ��绰��ͬ�ľͷ�������
        if (this->contaceList[i]->phoneNum == phoneNum)
        {
            index = i;
            break;
        }     
    }
    // û�о�ֱ�ӷ���0
    return index;
}

/***
 * ɾ����ϵ��
 * */
void PhoneAddressBook::delUser()
{
    string phoneNum;
    cout << "��������룺";
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
        cout << "ɾ���ɹ�" << endl;    
    }
    
}

/***
 * ���浽����
 * */
void PhoneAddressBook::saveToFile()
{
    // cout << "save" << endl;
    ofstream ofs;
    ofs.open("phoneList.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "phoneList.txt��ʧ��" << endl;
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
 * �鿴
 * */
void PhoneAddressBook::showAllUser()
{
    for (int i = 0; i < this->contacesNum; i++)
    {
        cout << *(this->contaceList[i]) << endl;
    }
}

/***
 * �޸�
 * */
void PhoneAddressBook::modifyInfo(string phoneNum)
{
    
    int index = this->isExist(phoneNum);
    if (index == -1)
    {
        cout << "�ֻ��в����ڸ���ϵ��" << endl;
        return;
    }
    this->ui.showAddUserMenu(1);
    PhoneContace *phoneContace = NULL;
    phoneContace = new PhoneContace();
    cin >> *phoneContace;
    this->contaceList[index] = phoneContace;
    this->saveToFile();
    cout << "�޸ĳɹ�" << endl;
}

/***
 * ��ѯ
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
        cout << "���в����ڸ���ϵ��" << endl;
    }
}