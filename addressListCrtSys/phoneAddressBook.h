#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "addressBook.h"
#include "phonecontace.h"

using namespace std;

class PhoneAddressBook : public AddressBook
{
private:
    PhoneContace *contaceList;
public:
    int contacesNum;


    PhoneAddressBook(/* args */);
    void addUser();
    void delUser();
    void showAllUser();
    void modifyInfo();
    void findUserInfo();
    void getContacesNum();
    ~PhoneAddressBook();
};


