#pragma once
#include <iostream>
#include <string>
#include "phoneCardAddressBook.h"
#include "phoneAddressBook.h"
#include "addressBook.h"
#include "ui.h"

using namespace std;

class User
{
private:
    PhoneCardAddressBook pcab;
    PhoneAddressBook pab; 
    Ui ui;
public:
    User(/* args */);
    void addUser();
    void saveUser(AddressBook &adb);
    void delContase();
    void findContase();
    void modifyInfo();
    void showAllContaces();
    void fromPhoneToCard();
    void fromCardToPhone();
    ~User();
};


