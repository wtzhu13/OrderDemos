#include <iostream>
#include "phoneCardContace.h"
#include "phonecontace.h"

using namespace std;

//������������,�ֻ�����ϵ��
ostream& operator<<(ostream& out, PhoneCardContace& p) 
{
	out << "name:" << p.name << " num:" << p.phoneNum;
	return out;
}

//�������������,�ֻ�����ϵ��
istream & operator>>(istream & in, PhoneCardContace& p){
    in >> p.name >> p.phoneNum;
    return in;
}

//����������������ֻ���ϵ��
istream & operator>>(istream & in, PhoneContace & A)
{
    in >> A.name >> A.phoneNum >> A.nativePlace >> A.qqNum;
    return in;
}

//���������������ֻ���ϵ��
ostream& operator<<(ostream& out, PhoneContace& p) {
	out << "name:" << p.name << " num:" << p.phoneNum << " nativePlace:" << p.nativePlace << " QQ:" << p.qqNum;
	return out;
}