/***********************************************************
* 版权所有(C) 
* All rights reserved.
*
* 文件名称：user.cpp
* 文件标识：无
* 内容摘要：该代码用于获取满足后缀要求的第一个文件
* 其它说明：无
* 当前版本： 
* 作    者： 
* 完成日期： 
*
* 修改记录：
* 修改日期： 
* 版 本 号： 
* 修 改 人： 
* 修改内容：创建
**********************************************************/
#include <iostream>
#include <cstring>
#include "bank.h"
using namespace std;
/*********************************************************
* 功能描述：用setUser()成员函数为数据成员赋值
* 输入参数：User类的所有数据成员
* 输出参数：无
* 返 回 值：无
* 其它说明：数组形参形式要注意
************************************************************/
void User::setUser(int acc, char nam[15], int pw, double bal,int sta,char ID[19],char add[20])
{
    account=acc;
    password=pw;
    strcpy(name,nam);
    balance=bal;
    status=sta;
    strcpy(IDnum,ID);
    strcpy(address,add);
}
/*********************************************************
* 功能描述：显示户主姓名
* 输入参数：无
* 输出参数：name-char *-户主姓名
* 返 回 值：无
* 其它说明：无
************************************************************/
void User::showName()
{
    cout<<"户主姓名："<<name<<endl;
}
/*********************************************************
* 功能描述：户主身份证号、户主家庭住址
* 输入参数：无
* 输出参数：IDnum-char *-户主身份证号，address-char *-户主家庭住址
* 返 回 值：无
* 其它说明：无
************************************************************/
void User::showIDaddress()
{
    cout<<"户主身份证号："<<IDnum<<endl;
    cout<<"户主家庭住址："<<address<<endl;
}
/*********************************************************
* 功能描述：显示账户余额
* 输入参数：prompt-提示词
* 输出参数：prompt-string-提示词，balance-double-账户余额
* 返 回 值：无
* 其它说明：无
************************************************************/
void User::showBalance(string prompt)
{
    cout<<prompt<<" "<<balance<<" 元"<<endl;
}
/*********************************************************
* 功能描述：确认密码正误
* 输入参数：无
* 输出参数：无
* 返 回 值：right-正确时等于 true,否则为false
* 其它说明：调用输入密码函数，返回值为bool型
************************************************************/
bool User::passwordIsRight()
{
    int iPass;
    bool right = true;
    cout<<"输入密码：";
    iPass=inputPassword();
    if(iPass!=password)
    {
        right = false;
        cout<<"输入密码错误，不能继续操作！"<<endl;
    }
    return right;
}
/*********************************************************
* 功能描述：查看用户状态
* 输入参数：无
* 输出参数：无
* 返 回 值：normal-true or false (bool型)
* 其它说明：若状态为0，返回正常，否则输出用户状态挂失或销户
************************************************************/
bool User::isNormalUser()
{
    bool normal = true;
    if(status!=0)
    {
        normal = false;
        cout<<"该账户处于"<<(status==1?"挂失":"销户")<<"状态，不能继续操作..."<<endl;
    }
    return normal;
}
