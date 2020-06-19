#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "addressBook.h"
#include "phonecontace.h"
#include "ui.h"

using namespace std;

class PhoneAddressBook : public AddressBook
{
private:
    
public:
    int contacesNum;
    PhoneContace **contaceList;
    Ui ui;

    PhoneAddressBook(/* args */);
    void addUser();
    void delUser();
    void showAllUser();
    void modifyInfo();
    void findUserInfo();
    void getContacesNum();
    void initContacesList();
    int isExist(string phoneNum);
    void saveToFile();
    ~PhoneAddressBook();
};


