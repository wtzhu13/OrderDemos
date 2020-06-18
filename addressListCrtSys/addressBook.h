#pragma once
#include <iostream>
#include <string>

class AddressBook
{
private:
    /* data */
public:
    AddressBook(/* args */){};
    virtual void addUser() = 0;
    virtual void delUser() = 0;
    virtual void showAllUser() = 0;
    virtual void modifyInfo() = 0;
    virtual void findUserInfo() = 0;
    virtual ~AddressBook(){};
};

