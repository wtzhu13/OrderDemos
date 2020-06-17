/***********************************************************
* ��Ȩ����(C)
* All rights reserved.
*
* �ļ����ƣ�bank.h
* �ļ���ʶ����
* ����ժҪ���ô������ڻ�ȡ�����׺Ҫ��ĵ�һ���ļ�
* ����˵������
* ��ǰ�汾��
* ��    �ߣ�
* ������ڣ�
*
* �޸ļ�¼����
* �޸����ڣ�
* �� �� �ţ�
* �� �� �ˣ�
* �޸����ݣ�����
**********************************************************/
#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include <string>
using namespace std;
const int upNum=2000; //ϵͳ������ɵ��û���
class Bank;
class User
{
public:
    void setUser(int acc, char *nam, int pw, double bal,int sta,char *ID,char *add);
    void showName();
    void showIDaddress();
    void showBalance(string prompt); //��ʾ��ǰ�������ʾ��prompt
    bool passwordIsRight();   //У�����룬�����������ȷ�򷵻�true
    bool isNormalUser(); //��ȡ�ת�ʵȹ��ܣ���Ҫ�˻�����������̬����������״̬ʱ����true���������η���false����ʾ
    friend class Bank;   //��Bank����Ϊ��Ԫ�࣬������������ݳ�Ա
 
 
private:
    int account; //�˺�
    int password;  //����
    char name[15];   //�û���
    double balance;  //�˻����
    int status;  //״̬ 0-����  1-��ʧ  2-����
    char IDnum[19];//���֤��
    char address[15];//��ͥסַ
};
 
class Bank
{
public:
    Bank();  //��ʼǰ���ļ��ж����ݣ�����������
    ~Bank();   //�������ǰ���������е�����д�뵽�ļ���
    void work();  //ҵ������
    void openAccount(); //����
    void cancelAccount();  //ע���˻�
    void save();   //���
    void withdraw();   //ȡ��
    void showAccount(); //��ѯ���
    void transferAccounts();  //ת��
    void reportLoss();  //��ʧ
    void cancelLoss();  //�����ʧ
    void updatePassword();   //��������
    int getUser();  //�����˺Ų�ѯ�û��������û��ڶ��������е��±�
	// fun: 	д�������ļ�
	// param:	pFileName	- �ļ���
	// ret: 	true		- д�ɹ���
	//			false		- дʧ��
	bool  WriteBinFile(const char* pFileName);
 
	// fun: 	���������ļ�
	// param:	pFileName	- �ļ���
	// ret: 	true		- �ɹ���
	//			false		- ʧ��
	bool  ReadBinFile(const char* pFileName);
private:
    int N;  //ʵ�ʵ��û���Ŀ
    User *users[upNum];  //User���飬�Ŀռ䰡���Ľ�������1.����ָ�����飻2. ��̬���飻3. ����
};
 
int pass();  //ҵ��Ա��¼
int chooseInMenu(); //��ʾ�˵�����ҵ��Աѡ��
int inputPassword();   //���ؼ������������
 
#endif // BANK_H_INCLUDED