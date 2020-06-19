#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "addressBook.h"
#include "phoneCardContace.h"
#include "ui.h"

using namespace std;

class PhoneCardAddressBook : public AddressBook
{
private:
    /* data */
public:
    int contacesNum;
    PhoneCardContace **contaceList;
    Ui ui;

    PhoneCardAddressBook(/* args */);
    ~PhoneCardAddressBook();
    void addUser();
    void delUser();
    void showAllUser();
    void modifyInfo(string phoneNum);
    void findUserInfo(string name);
    void getContacesNum();
    void initContacesList();
    int isExist(string phoneNum);
    void saveToFile();
};


