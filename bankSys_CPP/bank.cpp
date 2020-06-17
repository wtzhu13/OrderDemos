/***********************************************************
* ��Ȩ����(C) * All rights reserved.
*
* �ļ����ƣ�bank.cpp
* �ļ���ʶ����
* ����ժҪ���ô������ڻ�ȡ�����׺Ҫ��ĵ�һ���ļ�
* ����˵������
* ��ǰ�汾��V1.0
* ��    �ߣ� 
* �������*
* �޸ļ�¼����
* �޸����ڣ�
* �� �� �ţ�V1.0
* �� �� �ˣ� 
* �޸����ݣ�����
**********************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bank.h"
#include <ctype.h>
using namespace std;
//static int old_count=0;//��֤ÿ�ε��ù��캯��ʱ���ٴ������û�����
const static char* cs_FileName = "account_Bin.dat";
/*********************************************************
* �����������ù��캯����ȡ�ļ��б����ҵ������
* ���������cs_FileName\pFileName
* �����������
* �� �� ֵ����
* ����˵�����ö������ļ����룬��ȡʱ��ios::app�����ʽ���ļ�
            ÿ��ѭ����ȡ��ʱ�򿪱��¿ռ䡣
* ����˵����ʹ��eek()˵����eek()ֻ�ǲ鿴�������һ��Ԫ�أ�������ȡ�����ļ��ڲ���ָ�벻������ƶ���
************************************************************/
Bank::Bank()
{
   ReadBinFile(cs_FileName);
  // ReadTxtFile("account.dat");
}
bool  Bank::ReadBinFile(const char* pFileName)
{// note: ��ȡ˳�������дһ�£��ο� WriteBinFile
	 ifstream infile(pFileName,ios::app|ios::binary);//��ʹ��ios::app�������ʽ���ļ���д�������������ļ�β!!!!!
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        return false;
    }
    int i=0;
    while(infile.peek()!=EOF&&i<upNum)//�������ļ���β�����û������ﵽ���޵�ʱ���˳�ѭ��
    {
        User *tmp_user=new User();//���ٿռ�
        if(NULL==tmp_user)
        {
            cout<<"no enough momory\n"<<endl;
            exit(1);
        }
        infile.read((char*)tmp_user, sizeof(User));//����ΪUser���������ݳ�Ա���ܳ���
        users[i]=tmp_user;
        cout<<users[i]->account<<" "<<users[i]->password<<" "<<users[i]->balance<<endl;
        i++;
    }
    N = i; //�þ�̬���ݳ�Ա
    //old_count=N;//���û���Ŀ
    infile.close();
    return true;
}
 
/*********************************************************
* �������������������������˳�ϵͳʱ�������ݱ��浽�ļ���
* �����������
* �����������
* �� �� ֵ����
* ����˵����(1)�ö����ƴ���
            (2)׷�Ӻ͸��Ǽ�������
************************************************************/
Bank::~Bank()
{
 
    WriteBinFile(cs_FileName);
}
 
bool  Bank::WriteBinFile(const char* pFileName)
{
 
	ofstream outfile(pFileName, ios::binary);//��1��ios::binary������ʽ�ǡ����ǡ�����ԭ�����ݲ�������д���Ѿ�����Ҫ֮ǰ�����ݣ�֮ǰ�����Ѿ������������ˣ��п��ܸ���֮ǰ�����ݣ������ı䣬���������е�Ϊ׼����д���ļ���
	                                            //��2��ios::app|ios::binary������ʽ�ǡ�׷�ӡ�����ԭ���ļ���������������ݣ�ԭ�����ݲ��ı䣩
	                                            //(3)Ҳ����ʹ��ios::out|ios::binary��Ȼ�ⲻ��׷�ӣ�����ios::out��ԭ������ȫ������˵ģ����ܴ洢���ļ���
    if(!outfile)    //�����ļ��򿪲����Ƿ�ɹ������ɹ�����ʾ���˳���
    {
        cerr<<"open error!"<<endl;
        return false;
    }
    int i;
    for(i=0; i<N; i++)//����i=old_count,������ʽ�ǡ�׷�ӡ���ʹ��//������i=0.i=0������ʽ�ǡ����ǡ�ʹ��
    {
        outfile.write((char*)users[i], sizeof(User));//����ΪUser���������ݳ�Ա���ܳ���
        cout<<endl;
    }
    outfile.close();
    for(int i=0; i<N; i++)
    {
        if(NULL!=users[i])
        {
            delete users[i];//�ͷſռ�
            users[i]=NULL;
        }
    }
    return true;
 
}
/*********************************************************
* ��������������ҵ��
* �����������
* �����������
* �� �� ֵ����
* ����˵����ѭ�����У�����0�˳�ѭ��
************************************************************/
void Bank::work()
{
    int iChoice;   //����ѡ��ϵͳ����
    //����ҵ��
    do
    {
        iChoice = chooseInMenu();  //�Ӳ˵��л�ù��ܴ���
        switch(iChoice)
        {
        case 1:
            openAccount(); //����
            break;
        case 2:
            cancelAccount();  //ע���˻�
            break;
        case 3:
            save();  //���
            break;
        case 4:
            withdraw();   //ȡ��
            break;
        case 5:
            showAccount(); //��ѯ���
            break;
        case 6:
            transferAccounts();  //ת��
            break;
        case 7:
            reportLoss();  //��ʧ
            break;
        case 8:
            cancelLoss();  //�����ʧ
            break;
        case 9:
            updatePassword();   //��������
            break;
        case 0:
            cout<<"��ӭ������. "<<endl;
        }
    }
    while(iChoice);
}
 
/*********************************************************
* ��������������
* ���������acc-int-�˺�
             pw-int-����
             nam-char *-����
             bal-double-���
             sta-int-״̬
             ID-char *-���֤��
             add-char *-������ַ
* �����������
* �� �� ֵ����
* ����˵�����ڽ���ϵͳʱ���ڶ������ݹ����У��Ѿ���¼���û���ΪN���������ж�Ӧ�±�Ϊ0~N-1
  ����ʱҪ����һ���û���ֻҪΪ�±�ΪN������Ԫ����ֵ�����ڳɹ�֮����N++���ɡ�
  �˺���ϵͳ�Զ�����(10001+���)����֤��������������˳�����ӵ�ʱ�򣬾ͱ�֤��������
  ���������֤�š�������ַ��Ϊ�ַ����顣
************************************************************/
void Bank::openAccount()
{
    if(N==upNum)
    {
        cout<<"�����û����Ѿ��ﵽ���ޣ������ٿ���";
        return;
    }
    //��������������ҵ��
    int acc;   //�˺�
    char nam[15]={0};   //����
    int pw;   //����
    double bal;   //���
    int sta;   //״̬
    char ID[19]={0};  //���֤��
    char add[20]={0};   //��ͥסַ
    cout<<"���ڿ���"<<endl;
    acc=10001+N;
    cout<<"�˺ţ�"<<acc<<endl;
    cout<<"����������";
    cin>>nam;
    cout<<"�������֤�ţ�";
    cin>>ID;
    cout<<"������ͥסַ��";
    cin>>add;
    int iPass1, iPass2;
    cout<<"���룺";
    iPass1=inputPassword();  //��������1
    cout<<"ȷ�����룺";
    iPass2=inputPassword();  //��������2
    if(iPass1==iPass2)
    {
        pw=iPass1;
        sta=0; //�˻�״̬Ϊ��������
        cout<<"�����";
        cin>>bal;
        cout<<" ok";
        users[N]=new User;
        users[N]->setUser(acc, nam, pw, bal, sta,ID,add);
        N++; //��ʽ�û�������1��ȷ�������û��Ѿ�����
        cout<<"�ɹ�������"<<endl;
    }
    else
    {
        cout<<"�������벻һ�£�δ�ɹ�������"<<endl; //û��N++��������ֵ��Ч
    }
}
 
/*********************************************************
* ����������ע���˻�
* �����������
* �����������
* �� �� ֵ����
* ����˵�����ҵ��˻���������״̬��Ϊ2-ע�����ɡ�
            ע��ǰӦ�ü����Ӧ����ȡ����ע��
************************************************************/
void Bank::cancelAccount()
{
    int who;  //���ҵ����˺��������ж�Ӧ���±�
    who = getUser();  //�����˺Ų�ѯ�û��������û����±�
    if(who>=0)   //˵��id�˻�����
    {
        users[who]->showName();
        if(users[who]->passwordIsRight())
        {
            users[who]->showBalance("���");   //��ʾ"���"���֣���ʾ���
            cout<<"ȷ��������y/n����";
            if(tolower(getchar())=='y')
            {
                users[who]->showBalance("�����ɹ�������ȡ����Ϊ");
                users[who]->balance=0;  //ȡ�������0
                users[who]->status=2;  //״̬��Ϊע��
            }
            else
            {
                cout<<"��ȡ���˲���������ʧ�ܣ�"<<endl;
            }
            fflush(stdin);  //�����getchar()ʱ�ڼ��̻����е�����������Ӱ���������
        }
    }
}
 
/*********************************************************
* �������������
* ���������money-double-�����
* �����������
* �� �� ֵ����
* ����˵������Ҫ��֤�˻����ڣ��Ҵ�������״̬������ǰȷ���˻��û����֡�
             �������ʾ�˻���
************************************************************/
void Bank::save()
{
    int who;
    double money;
    who = getUser();  //�����˺Ų�ѯ�û��������û����±�
    if(who>=0)   //˵��id�˻�����
    {
        if(users[who]->status==0)
        {
            users[who]->showName();
            cout<<"������";
            cin>>money;
            users[who]->balance+=money;
            users[who]->showBalance("��������");
        }
        else if(users[who]->status==1)
        {
            cout<<"���û����ڹ�ʧ״̬�����ʧ�ܣ�"<<endl;
        }
        else
        {
            cout<<"���û��Ѿ����������ʧ�ܣ�"<<endl;
        }
    }
    return;
}
 
/*********************************************************
* ����������ȡ��
* ���������monney-double-ȡ����
* �����������
* �� �� ֵ����
* ����˵������Ҫ��֤�˻����ڣ��Ҵ�������״̬�����⣬���Ҫ�㹻ȡ��
            ȡ����Ҫȷ���������������룬ȡ�����ʾ��
************************************************************/
void Bank::withdraw()
{
    int who;
    double money;
    who = getUser();  //�����˺Ų�ѯ�û��������û����±�
    if(who>=0)   //˵��id�˻�����
    {
        if(users[who]->isNormalUser())
        {
            users[who]->showName();
            if(users[who]->passwordIsRight())
            {
                cout<<"����ȡ��";
                cin>>money;
                if(money>users[who]->balance)  //�ף�����͸֧
                {
                    cout<<"���㣬ȡ��ʧ�ܣ�"<<endl;
                }
                else
                {
                    users[who]->balance-=money;
                    users[who]->showBalance("ȡ��󣬻���");
                }
            }
        }
 
    }
    return;
}
 
/*********************************************************
* ������������ѯ�˻�
* �����������
* ���������sta[users[who]->status]-string-�û�״̬
* �� �� ֵ����
* ����˵������Ҫȷ���û����������룬��ʾ�˻���Ϣ��������״̬
************************************************************/
void Bank::showAccount()
{
    int who;
    string sta[3]= {"����","��ʧ","�Ѿ�����"};
    who = getUser();  //�����˺Ų�ѯ�û��������û����±�
    if(who>=0)   //˵��id�˻�����
    {
        users[who]->showName();
        if(users[who]->passwordIsRight())
        {
            users[who]->showBalance("���");
            cout<<"״̬��"<<sta[users[who]->status]<<endl;
        }
    }
    return;
}
 
/*********************************************************
* ����������ת��
* ���������money-double-ת�˽��
* �����������
* �� �� ֵ����
* ����˵������Ҫ��֤�����˻������ڣ��Ҵ�������״̬�����⣬ת���˻������Ҫ�㹻��
            ת���˻���Ҫ�������룬ת���˻�����Ҫ��ֻ��Ҫȷ���û��Ƿ���ڡ�ת������ʾ��
************************************************************/
void Bank::transferAccounts()
{
    int whoout, whoin;
    double money;
    cout<<"ת����";
    whoout = getUser();  //�����˺Ų�ѯ�û��������û����±�
    if(whoout>=0)   //˵��id�˻�����
    {
        if(users[whoout]->isNormalUser())
        {
            users[whoout]->showName();
            if(users[whoout]->passwordIsRight())
            {
                cout<<"����ת�˽�";
                cin>>money;
                if(money>users[whoout]->balance)  //�ף�����͸֧
                {
                    cout<<"���㣬ת��ʧ�ܣ�"<<endl;
                }
                else
                {
                    cout<<"ת����";
                    whoin = getUser();  //�����˺Ų�ѯ�û��������û����±�
                    if(whoin>=0)   //˵��id�˻�����
                    {
                        if(users[whoin]->isNormalUser())
                        {
                            users[whoout]->balance-=money;
                            users[whoin]->balance+=money;
                            users[whoout]->showBalance("ת�˺�������");
                        }
                    }
                }
            }
        }
    }
    return;
}
 
/*********************************************************
* ������������ʧ�˻�
* �����������
* �����������
* �� �� ֵ����
* ����˵�����ҵ��˻���������״̬��Ϊ1-��ʧ���ɡ�
            ����Ѿ��������ܹ�ʧ����Ҫ��֤�û������������롣
************************************************************/
void Bank::reportLoss()
{
    int who;
    who = getUser();  //�����˺Ų�ѯ�û��������û����±�
    if(who>=0)   //˵��id�˻�����
    {
        users[who]->showName();
        if(users[who]->passwordIsRight())
        {
            if(users[who]->status==0)
            {
                users[who]->status=1;
                cout<<"��ʧ�ɹ�"<<endl;
            }
            else if(users[who]->status==1)
            {
                cout<<"���˻��Ѿ����ڹ�ʧ״̬"<<endl;
            }
            else
            {
                cout<<"���˻������������ܹ�ʧ"<<endl;
            }
        }
    }
    return;
}
 
/*********************************************************
* ���������������ʧ
* �����������
* �����������
* �� �� ֵ����
* ����˵�����ҵ��˻����鿴��״̬��Ϊ��������Ҫ��ң���Ϊ�������ܽ�ң�
            ��Ϊ��ʧ����״̬��Ϊ0-�������ɡ�
************************************************************/
void Bank::cancelLoss()
{
    int who;
    who = getUser();  //�����˺Ų�ѯ�û��������û����±�
    if(who>=0)   //˵��id�˻�����
    {
        users[who]->showName();
        if(users[who]->passwordIsRight())
        {
            if(users[who]->status==0)
            {
                cout<<"���˻���������״̬������Ҫ�����ʧ"<<endl;
            }
            else if(users[who]->status==1)
            {
                users[who]->status=0;
                cout<<"�����ʧ�ɹ�"<<endl;
            }
            else
            {
                cout<<"���˻���������������Ч"<<endl;
            }
        }
    }
    return;
}
 
/*********************************************************
* ����������������
* �����������
* �����������
* �� �� ֵ����
* ����˵�����ҵ��˻������������벢ȷ�ϣ������β�ͬ�޸�ʧ��
************************************************************/
void Bank::updatePassword()
{
    int who;
    int iPass1, iPass2;
    who = getUser();  //�����˺Ų�ѯ�û��������û����±�
    if(who>=0)   //˵��id�˻�����
    {
        users[who]->showName();
        if(users[who]->passwordIsRight())
        {
            cout<<"�����룺";
            iPass1=inputPassword();  //��������1
            cout<<"ȷ�����룺";
            iPass2=inputPassword();  //��������2
            if(iPass1==iPass2)
            {
                users[who]->password=iPass1;
                cout<<"�޸ĳɹ���"<<endl;
            }
            else
            {
                cout<<"�������벻ͬ���޸�ʧ�ܣ�"<<endl;
            }
        }
    }
    return;
}
 
/*********************************************************
* ���������������˺Ų�ѯ�û��������û��������е��±�
* ���������id-int-Ҫ��ѯ�û����˺�
* �����������
* �� �� ֵ��index-Ϊ�û��˺�-10001��ֵ����ֵ��0~N-1�䣩
* ����˵�������˺��Զ�������ʹ���˺����򣬱�ģ����ö��ֲ���
************************************************************/
int Bank::getUser()
{
    int id;
    cout<<"�˺ţ�";
    cin>>id;
    int index=-1;
    int low=0, high=N-1, mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(users[mid]->account==id)
        {
            index=mid;
            break;   //�ҵ��ˣ������˳�ѭ��
        }
        else if (users[mid]->account>id)
            high=mid-1;
        else
            low=mid+1;
    }
    if (index<0)
        cout<<"���û������ڣ����β���ʧ�ܣ�"<<endl;
    return index; //���ҵ�����ֵ��0~N-1�䣬���򣬱���-1
}