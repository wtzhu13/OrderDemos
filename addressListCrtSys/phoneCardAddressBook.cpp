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
 * ��ʼ���û��б�
 * */
void PhoneCardAddressBook::initContacesList()
{
    ifstream ifs;
    ifs.open("cardList.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "phoneList.txt��ʧ��" << endl;
    }
    // ��ʱ��������ļ�����
    string name;
    string phoneNum;
    int i = 0;
    // �����ļ�
    while (ifs >> name && ifs >> phoneNum )
    {
        PhoneCardContace *phoneCardContace = NULL;
        phoneCardContace = new PhoneCardContace();
        phoneCardContace->setInfo(name, phoneNum);
        // ���ļ�������ӵ��б�
        this->contaceList[i] = phoneCardContace;
        i++;
    }
    ifs.close();
}

/***
 * ��ȡ��ϵ������
 * */
void PhoneCardAddressBook::getContacesNum()
{
    // �����ļ�
    ifstream ifs;
    ifs.open("cardList.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "cardList.txt��ʧ��" << endl;
    }
    string buf;
    // �����ļ�����¼����
    while (getline(ifs, buf))
    {
        this->contacesNum++;
    } 
    ifs.close();
}

/***
 * ����û�
 * */
void PhoneCardAddressBook::addUser()
{
    // ���Ȼ�ȡ�û�����
    this->getContacesNum();
    // cout << this->contacesNum << endl;
    if (this->contacesNum >= 1000)
    {
        cout << "�ռ䲻��" << endl;
        return;
    }

    PhoneCardContace *phoneCardContace = NULL;
    phoneCardContace = new PhoneCardContace();
    cin >> *phoneCardContace;

    // �û�������һ
    int newContacesNum = this->contacesNum + 1;
    // �½�һ����ʱ���
    PhoneCardContace **newContaceList = new PhoneCardContace*[newContacesNum];
    
    cout << *contaceList[0] << endl;
    // �������ݿ������¿ռ�
    
    for (int i = 0; i < this->contacesNum; i++)
    {
        newContaceList[i] = this->contaceList[i];
    }

    // �������û��Ž�����
    newContaceList[newContacesNum] = phoneCardContace;
    // cout << "添加用户成功!!!" << endl;
    // �ͷ�ԭ�пռ�
    delete[] this->contaceList;
    this->contaceList = NULL;
    // ���µĵ�ַ���б�ָ��
    this->contaceList = newContaceList;
    // �ͷ��¿ռ�
    delete[] newContaceList;
    newContaceList = NULL;
    // �û�����һ
    this->contacesNum++;

    // ����Ϣ���浽����
    ofstream ofs;
    ofs.open("cardList.txt", ios::app);
    ofs << phoneCardContace->name << " " << phoneCardContace->phoneNum << endl;
    ofs.close();
    cout << "����û��ɹ�" << endl;

}

/***
 * �ж���ϵ���Ƿ����
 * */
int PhoneCardAddressBook::isExist(string phoneNum)
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
 * ���浽����
 * */
void PhoneCardAddressBook::saveToFile()
{
    ofstream ofs;
    ofs.open("cardList.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "cardList.txt��ʧ��" << endl;
        return;
    }
    
    for (int i = 0; i < this->contacesNum; i++)
    {
        ofs << this->contaceList[i]->name << " "
            << this->contaceList[i]->phoneNum << endl;
    }
    ofs.close();
}

/***
 * ɾ��
 * */
void PhoneCardAddressBook::delUser()
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
 * �鿴
 * */
void PhoneCardAddressBook::showAllUser()
{
    for (int i = 0; i < this->contacesNum; i++)
    {
        cout << *(this->contaceList[i]) << endl;
    }
}

/***
 * ��ѯ
 * */
void PhoneCardAddressBook::modifyInfo(string phoneNum)
{
    int index = this->isExist(phoneNum);
    if (index == -1)
    {
        cout << "���в����ڸ���ϵ��" << endl;
        return;
    }
    this->ui.showAddUserMenu(2);
    PhoneCardContace *phoneCardContace = NULL;
    phoneCardContace = new PhoneCardContace();
    cin >> *phoneCardContace;
    this->contaceList[index] = phoneCardContace;
    this->saveToFile();
    cout << "�޸ĳɹ�" << endl;
}

void PhoneCardAddressBook::findUserInfo(string name)
{
    int flag = 0;
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
