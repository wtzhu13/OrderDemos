#pragma once
#include <iostream>
#include <string>

using namespace std;

class AddressBook
{
private:
    /* data */
public:
    AddressBook(/* args */){};
    virtual void addUser() = 0;
    virtual void delUser() = 0;
    virtual void showAllUser() = 0;
    void modifyInfo(string phoneNum){};
    void findUserInfo(string phoneNum){ };
    virtual ~AddressBook(){};
};

