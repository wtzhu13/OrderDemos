#pragma once
#include <iostream>
#include <string>
#include "phoneCardContace.h"

using namespace std;

/**
 * �ֻ���ϵ����
 * */
class PhoneContace : public PhoneCardContace
{
    friend ostream& operator<<(ostream& out, PhoneContace& p);
    friend istream& operator>>(istream& in, PhoneContace& A);
private:
    string nativePlace;
    string qqNum;
public:
    PhoneContace();
    ~PhoneContace();
    void setInfo();
    void modifyInfo();
};


