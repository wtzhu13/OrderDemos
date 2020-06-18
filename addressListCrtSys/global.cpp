#include <iostream>
#include "phoneCardContace.h"
#include "phonecontace.h"

using namespace std;

//重载输出运算符,手机卡联系人
ostream& operator<<(ostream& out, PhoneCardContace& p) 
{
	out << "name:" << p.name << " num:" << p.phoneNum;
	return out;
}

//重载输入运算符,手机卡联系人
istream & operator>>(istream & in, PhoneCardContace& p){
    in >> p.name >> p.phoneNum;
    return in;
}

//重载输入运算符，手机联系人
istream & operator>>(istream & in, PhoneContace & A)
{
    in >> A.name >> A.phoneNum >> A.nativePlace >> A.qqNum;
    return in;
}

//重载输出运算符，手机联系人
ostream& operator<<(ostream& out, PhoneContace& p) {
	out << "name:" << p.name << " num:" << p.phoneNum << " nativePlace:" << p.nativePlace << " QQ:" << p.qqNum;
	return out;
}