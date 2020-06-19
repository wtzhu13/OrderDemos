#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "addressBook.h"
#include "phoneCardContace.h"

using namespace std;

class PhoneCardAddressBook : public AddressBook
{
private:
    /* data */
public:
    int contacesNum;
    PhoneCardContace **contaceList;

    PhoneCardAddressBook(/* args */);
    ~PhoneCardAddressBook();
    void addUser();
    void delUser();
    void showAllUser();
    void modifyInfo();
    void findUserInfo();
    void getContacesNum();
    void initContacesList();
};


