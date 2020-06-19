#pragma once
#include <iostream>
#include <string>
#include "phoneCardContace.h"

using namespace std;

/**
 * 手机联系人类
 * */
class PhoneContace : public PhoneCardContace
{
    friend ostream& operator<<(ostream& out, PhoneContace& p);
    friend istream& operator>>(istream& in, PhoneContace& A);
private:
    
public:
    string nativePlace;
    string qqNum;

    PhoneContace();
    ~PhoneContace();
    void setInfo(string name, string phoneNum, string nativePlace, string QQNum);
    void modifyInfo(string name, string phoneNum, string nativePlace, string QQNum);
};


