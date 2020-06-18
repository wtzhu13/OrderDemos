#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * 手机卡联系人类
 * */
class PhoneCardContace
{
    friend ostream& operator<<(ostream& out, PhoneCardContace& p);
    friend istream& operator>>(istream& in, PhoneCardContace& p);
private:

protected:
    string name;
    string phoneNum;
public:
    PhoneCardContace(string name = "0", string phoneNum = "0");
    ~PhoneCardContace();  
    void setInfo(string name, string phoneNum);
    void modifyInfo();
};




