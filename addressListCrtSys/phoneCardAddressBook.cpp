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
    // ���µĵ�ַ���б�ָ��
    this->contaceList = newContaceList;
    // �ͷ��¿ռ�
    delete[] newContaceList;
    // �û�����һ
    this->contacesNum++;

    // ����Ϣ���浽����
    ofstream ofs;
    ofs.open("cardList.txt", ios::app);
    ofs << phoneCardContace->name << " " << phoneCardContace->phoneNum << endl;
    ofs.close();
    cout << "����û��ɹ�" << endl;

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
