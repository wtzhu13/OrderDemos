/***********************************************************
* 版权所有(C) * All rights reserved.
*
* 文件名称：bank.cpp
* 文件标识：无
* 内容摘要：该代码用于获取满足后缀要求的第一个文件
* 其它说明：无
* 当前版本：V1.0
* 作    者： 
* 完成日期*
* 修改记录：无
* 修改日期：
* 版 本 号：V1.0
* 修 改 人： 
* 修改内容：创建
**********************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bank.h"
#include <ctype.h>
using namespace std;
//static int old_count=0;//保证每次调用构造函数时不再存入老用户数据
const static char* cs_FileName = "account_Bin.dat";
/*********************************************************
* 功能描述：用构造函数读取文件中保存的业务数据
* 输入参数：cs_FileName\pFileName
* 输出参数：无
* 返 回 值：无
* 其它说明：用二进制文件存入，读取时用ios::app输出方式打开文件
            每次循环读取的时候开辟新空间。
* 其他说明：使用eek()说明：eek()只是查看缓冲的下一个元素，并不读取（即文件内部的指针不会向后移动）
************************************************************/
Bank::Bank()
{
   ReadBinFile(cs_FileName);
  // ReadTxtFile("account.dat");
}
bool  Bank::ReadBinFile(const char* pFileName)
{// note: 读取顺序必须与写一致，参看 WriteBinFile
	 ifstream infile(pFileName,ios::app|ios::binary);//可使用ios::app以输出方式打开文件，写入的数据添加在文件尾!!!!!
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        return false;
    }
    int i=0;
    while(infile.peek()!=EOF&&i<upNum)//当读到文件结尾或者用户数量达到上限的时候退出循环
    {
        User *tmp_user=new User();//开辟空间
        if(NULL==tmp_user)
        {
            cout<<"no enough momory\n"<<endl;
            exit(1);
        }
        infile.read((char*)tmp_user, sizeof(User));//长度为User类所有数据成员的总长度
        users[i]=tmp_user;
        cout<<users[i]->account<<" "<<users[i]->password<<" "<<users[i]->balance<<endl;
        i++;
    }
    N = i; //用静态数据成员
    //old_count=N;//老用户数目
    infile.close();
    return true;
}
 
/*********************************************************
* 功能描述：用析构函数，在退出系统时，将数据保存到文件中
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：(1)用二进制存入
            (2)追加和覆盖见代码中
************************************************************/
Bank::~Bank()
{
 
    WriteBinFile(cs_FileName);
}
 
bool  Bank::WriteBinFile(const char* pFileName)
{
 
	ofstream outfile(pFileName, ios::binary);//（1）ios::binary这种形式是“覆盖”（把原来内容擦掉重新写，已经不需要之前的内容，之前内容已经读到程序中了，有可能给变之前的内容，如若改变，将按程序中的为准重新写入文件）
	                                            //（2）ios::app|ios::binary这种形式是“追加”（在原来文件基础上添加新内容，原有内容不改变）
	                                            //(3)也不能使用ios::out|ios::binary虽然这不是追加，但是ios::out将原有内容全部清除了的，不能存储到文件中
    if(!outfile)    //测试文件打开操作是否成功，不成功则提示后退出。
    {
        cerr<<"open error!"<<endl;
        return false;
    }
    int i;
    for(i=0; i<N; i++)//不用i=old_count,这种形式是“追加”中使用//而是用i=0.i=0这种形式是“覆盖”使用
    {
        outfile.write((char*)users[i], sizeof(User));//长度为User类所有数据成员的总长度
        cout<<endl;
    }
    outfile.close();
    for(int i=0; i<N; i++)
    {
        if(NULL!=users[i])
        {
            delete users[i];//释放空间
            users[i]=NULL;
        }
    }
    return true;
 
}
/*********************************************************
* 功能描述：办理业务
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：循环进行，输入0退出循环
************************************************************/
void Bank::work()
{
    int iChoice;   //用于选择系统功能
    //办理业务
    do
    {
        iChoice = chooseInMenu();  //从菜单中获得功能代码
        switch(iChoice)
        {
        case 1:
            openAccount(); //开户
            break;
        case 2:
            cancelAccount();  //注销账户
            break;
        case 3:
            save();  //存款
            break;
        case 4:
            withdraw();   //取款
            break;
        case 5:
            showAccount(); //查询余额
            break;
        case 6:
            transferAccounts();  //转账
            break;
        case 7:
            reportLoss();  //挂失
            break;
        case 8:
            cancelLoss();  //解除挂失
            break;
        case 9:
            updatePassword();   //更改密码
            break;
        case 0:
            cout<<"欢迎您再来. "<<endl;
        }
    }
    while(iChoice);
}
 
/*********************************************************
* 功能描述：开户
* 输入参数：acc-int-账号
             pw-int-密码
             nam-char *-姓名
             bal-double-金额
             sta-int-状态
             ID-char *-身份证号
             add-char *-储户地址
* 输出参数：无
* 返 回 值：无
* 其它说明：在进入系统时，在读入数据过程中，已经记录了用户数为N，在数组中对应下标为0~N-1
  开户时要增加一个用户，只要为下标为N的数组元素置值，并在成功之后令N++即可。
  账号由系统自动生成(10001+序号)，保证其连续，这样在顺序增加的时候，就保证了其有序。
  姓名、身份证号、储户地址都为字符数组。
************************************************************/
void Bank::openAccount()
{
    if(N==upNum)
    {
        cout<<"银行用户数已经达到上限，不能再开户";
        return;
    }
    //下面正常办理开户业务
    int acc;   //账号
    char nam[15]={0};   //姓名
    int pw;   //密码
    double bal;   //金额
    int sta;   //状态
    char ID[19]={0};  //身份证号
    char add[20]={0};   //家庭住址
    cout<<"正在开户"<<endl;
    acc=10001+N;
    cout<<"账号："<<acc<<endl;
    cout<<"户主姓名：";
    cin>>nam;
    cout<<"户主身份证号：";
    cin>>ID;
    cout<<"户主家庭住址：";
    cin>>add;
    int iPass1, iPass2;
    cout<<"密码：";
    iPass1=inputPassword();  //输入密码1
    cout<<"确认密码：";
    iPass2=inputPassword();  //输入密码2
    if(iPass1==iPass2)
    {
        pw=iPass1;
        sta=0; //账户状态为“正常”
        cout<<"存入金额：";
        cin>>bal;
        cout<<" ok";
        users[N]=new User;
        users[N]->setUser(acc, nam, pw, bal, sta,ID,add);
        N++; //正式用户数增加1，确认了新用户已经加入
        cout<<"成功开户！"<<endl;
    }
    else
    {
        cout<<"两次密码不一致，未成功开户！"<<endl; //没有N++，则读入的值无效
    }
}
 
/*********************************************************
* 功能描述：注销账户
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：找到账户，并将其状态改为2-注销即可。
            注销前应该检查余额，应该先取款再注销
************************************************************/
void Bank::cancelAccount()
{
    int who;  //查找到该账号在数组中对应的下标
    who = getUser();  //根据账号查询用户，返回用户的下标
    if(who>=0)   //说明id账户存在
    {
        users[who]->showName();
        if(users[who]->passwordIsRight())
        {
            users[who]->showBalance("余额");   //提示"余额"二字，显示金额
            cout<<"确认销户（y/n）？";
            if(tolower(getchar())=='y')
            {
                users[who]->showBalance("销户成功！本次取款金额为");
                users[who]->balance=0;  //取款后余额变0
                users[who]->status=2;  //状态变为注销
            }
            else
            {
                cout<<"你取消了操作，销户失败！"<<endl;
            }
            fflush(stdin);  //清除了getchar()时在键盘缓存中的遗留，以免影响后续操作
        }
    }
}
 
/*********************************************************
* 功能描述：存款
* 输入参数：money-double-存款金额
* 输出参数：无
* 返 回 值：无
* 其它说明：需要保证账户存在，且处于正常状态。存入前确认账户用户名字。
             存入后显示账户余额。
************************************************************/
void Bank::save()
{
    int who;
    double money;
    who = getUser();  //根据账号查询用户，返回用户的下标
    if(who>=0)   //说明id账户存在
    {
        if(users[who]->status==0)
        {
            users[who]->showName();
            cout<<"输入存款额：";
            cin>>money;
            users[who]->balance+=money;
            users[who]->showBalance("存款后，您有");
        }
        else if(users[who]->status==1)
        {
            cout<<"该用户处于挂失状态，存款失败！"<<endl;
        }
        else
        {
            cout<<"该用户已经销户，存款失败！"<<endl;
        }
    }
    return;
}
 
/*********************************************************
* 功能描述：取款
* 输入参数：monney-double-取款金额
* 输出参数：无
* 返 回 值：无
* 其它说明：需要保证账户存在，且处于正常状态。另外，余额要足够取。
            取款需要确认姓名并输入密码，取款后显示余额。
************************************************************/
void Bank::withdraw()
{
    int who;
    double money;
    who = getUser();  //根据账号查询用户，返回用户的下标
    if(who>=0)   //说明id账户存在
    {
        if(users[who]->isNormalUser())
        {
            users[who]->showName();
            if(users[who]->passwordIsRight())
            {
                cout<<"输入取款额：";
                cin>>money;
                if(money>users[who]->balance)  //亲，不玩透支
                {
                    cout<<"余额不足，取款失败！"<<endl;
                }
                else
                {
                    users[who]->balance-=money;
                    users[who]->showBalance("取款后，还有");
                }
            }
        }
 
    }
    return;
}
 
/*********************************************************
* 功能描述：查询账户
* 输入参数：无
* 输出参数：sta[users[who]->status]-string-用户状态
* 返 回 值：无
* 其它说明：需要确认用户并输入密码，显示账户信息包括余额和状态
************************************************************/
void Bank::showAccount()
{
    int who;
    string sta[3]= {"正常","挂失","已经销户"};
    who = getUser();  //根据账号查询用户，返回用户的下标
    if(who>=0)   //说明id账户存在
    {
        users[who]->showName();
        if(users[who]->passwordIsRight())
        {
            users[who]->showBalance("余额");
            cout<<"状态："<<sta[users[who]->status]<<endl;
        }
    }
    return;
}
 
/*********************************************************
* 功能描述：转账
* 输入参数：money-double-转账金额
* 输出参数：无
* 返 回 值：无
* 其它说明：需要保证两个账户都存在，且处于正常状态，另外，转出账户的余额要足够。
            转出账户需要输入密码，转入账户不需要，只需要确认用户是否存在。转出后显示余额。
************************************************************/
void Bank::transferAccounts()
{
    int whoout, whoin;
    double money;
    cout<<"转出自";
    whoout = getUser();  //根据账号查询用户，返回用户的下标
    if(whoout>=0)   //说明id账户存在
    {
        if(users[whoout]->isNormalUser())
        {
            users[whoout]->showName();
            if(users[whoout]->passwordIsRight())
            {
                cout<<"输入转账金额：";
                cin>>money;
                if(money>users[whoout]->balance)  //亲，不玩透支
                {
                    cout<<"余额不足，转账失败！"<<endl;
                }
                else
                {
                    cout<<"转出到";
                    whoin = getUser();  //根据账号查询用户，返回用户的下标
                    if(whoin>=0)   //说明id账户存在
                    {
                        if(users[whoin]->isNormalUser())
                        {
                            users[whoout]->balance-=money;
                            users[whoin]->balance+=money;
                            users[whoout]->showBalance("转账后，您还有");
                        }
                    }
                }
            }
        }
    }
    return;
}
 
/*********************************************************
* 功能描述：挂失账户
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：找到账户，并将其状态改为1-挂失即可。
            如果已经销户则不能挂失。需要查证用户名并输入密码。
************************************************************/
void Bank::reportLoss()
{
    int who;
    who = getUser();  //根据账号查询用户，返回用户的下标
    if(who>=0)   //说明id账户存在
    {
        users[who]->showName();
        if(users[who]->passwordIsRight())
        {
            if(users[who]->status==0)
            {
                users[who]->status=1;
                cout<<"挂失成功"<<endl;
            }
            else if(users[who]->status==1)
            {
                cout<<"该账户已经处于挂失状态"<<endl;
            }
            else
            {
                cout<<"该账户已销户，不能挂失"<<endl;
            }
        }
    }
    return;
}
 
/*********************************************************
* 功能描述：解除挂失
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：找到账户，查看其状态若为正常则不需要解挂，若为销户则不能解挂，
            若为挂失将其状态改为0-正常即可。
************************************************************/
void Bank::cancelLoss()
{
    int who;
    who = getUser();  //根据账号查询用户，返回用户的下标
    if(who>=0)   //说明id账户存在
    {
        users[who]->showName();
        if(users[who]->passwordIsRight())
        {
            if(users[who]->status==0)
            {
                cout<<"该账户处于正常状态，不需要解除挂失"<<endl;
            }
            else if(users[who]->status==1)
            {
                users[who]->status=0;
                cout<<"解除挂失成功"<<endl;
            }
            else
            {
                cout<<"该账户已销户，操作无效"<<endl;
            }
        }
    }
    return;
}
 
/*********************************************************
* 功能描述：改密码
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：找到账户，输入新密码并确认，若两次不同修改失败
************************************************************/
void Bank::updatePassword()
{
    int who;
    int iPass1, iPass2;
    who = getUser();  //根据账号查询用户，返回用户的下标
    if(who>=0)   //说明id账户存在
    {
        users[who]->showName();
        if(users[who]->passwordIsRight())
        {
            cout<<"新密码：";
            iPass1=inputPassword();  //输入密码1
            cout<<"确认密码：";
            iPass2=inputPassword();  //输入密码2
            if(iPass1==iPass2)
            {
                users[who]->password=iPass1;
                cout<<"修改成功！"<<endl;
            }
            else
            {
                cout<<"两次输入不同，修改失败！"<<endl;
            }
        }
    }
    return;
}
 
/*********************************************************
* 功能描述：输入账号查询用户，返回用户在数组中的下标
* 输入参数：id-int-要查询用户的账号
* 输出参数：无
* 返 回 值：index-为用户账号-10001的值（其值在0~N-1间）
* 其它说明：由账号自动产生，使按账号有序，本模块采用二分查找
************************************************************/
int Bank::getUser()
{
    int id;
    cout<<"账号：";
    cin>>id;
    int index=-1;
    int low=0, high=N-1, mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(users[mid]->account==id)
        {
            index=mid;
            break;   //找到了，立即退出循环
        }
        else if (users[mid]->account>id)
            high=mid-1;
        else
            low=mid+1;
    }
    if (index<0)
        cout<<"该用户不存在，本次操作失败！"<<endl;
    return index; //若找到，其值在0~N-1间，否则，保持-1
}