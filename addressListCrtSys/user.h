#pragma once
#include <iostream>
#include <string>
// #include "phoneCardAddressBook.h"
// #include "phoneAddressBook.h"
#include "ui.h"

using namespace std;

class User
{
private:
    // PhoneCardAddressBook pcab;
    // PhoneAddressBook pab; 
    Ui ui;
public:
    User(/* args */);
    void addUser();
    ~User();
};


