#pragma once
#include <iostream>
#include <string>
#include "addressBook.h"

class PhoneCardAddressBook : public AddressBook
{
private:
    /* data */
public:
    PhoneCardAddressBook(/* args */);
    ~PhoneCardAddressBook();
    void addUser();
    void delUser();
    void showAllUser();
    void modifyInfo();
    void findUserInfo();
};


