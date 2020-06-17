/***********************************************************
* 版权所有(C)
* All rights reserved.
*
* 文件名称：bank.h
* 文件标识：无
* 内容摘要：该代码用于获取满足后缀要求的第一个文件
* 其它说明：无
* 当前版本：
* 作    者：
* 完成日期：
*
* 修改记录：无
* 修改日期：
* 版 本 号：
* 修 改 人：
* 修改内容：创建
**********************************************************/
#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include <string>
using namespace std;
const int upNum=2000; //系统最多容纳的用户数
class Bank;
class User
{
public:
    void setUser(int acc, char *nam, int pw, double bal,int sta,char *ID,char *add);
    void showName();
    void showIDaddress();
    void showBalance(string prompt); //显示余额，前面加上提示词prompt
    bool passwordIsRight();   //校验密码，输入的密码正确则返回true
    bool isNormalUser(); //存款、取款、转帐等功能，需要账户处于正常姿态，处于正常状态时返回true，其他情形返回false并提示
    friend class Bank;   //将Bank声明为友元类，方便其访问数据成员
 
 
private:
    int account; //账号
    int password;  //密码
    char name[15];   //用户名
    double balance;  //账户余额
    int status;  //状态 0-正常  1-挂失  2-销户
    char IDnum[19];//身份证号
    char address[15];//家庭住址
};
 
class Bank
{
public:
    Bank();  //开始前从文件中读数据，存在数组中
    ~Bank();   //程序结束前，将数组中的数据写入到文件中
    void work();  //业务驱动
    void openAccount(); //开户
    void cancelAccount();  //注销账户
    void save();   //存款
    void withdraw();   //取款
    void showAccount(); //查询余额
    void transferAccounts();  //转账
    void reportLoss();  //挂失
    void cancelLoss();  //解除挂失
    void updatePassword();   //更改密码
    int getUser();  //输入账号查询用户，返回用户在对象数组中的下标
	// fun: 	写二进制文件
	// param:	pFileName	- 文件名
	// ret: 	true		- 写成功，
	//			false		- 写失败
	bool  WriteBinFile(const char* pFileName);
 
	// fun: 	读二进制文件
	// param:	pFileName	- 文件名
	// ret: 	true		- 成功，
	//			false		- 失败
	bool  ReadBinFile(const char* pFileName);
private:
    int N;  //实际的用户数目
    User *users[upNum];  //User数组，耗空间啊！改进方案：1.对象指针数组；2. 动态数组；3. 链表
};
 
int pass();  //业务员登录
int chooseInMenu(); //显示菜单并由业务员选择
int inputPassword();   //返回键盘输入的密码
 
#endif // BANK_H_INCLUDED