#include "phoneContace.h"

PhoneContace::PhoneContace (/* args */)
{
}

PhoneContace::~PhoneContace()
{
}


/**
 * 设置成员属性 
*/
void PhoneContace::setInfo(string name, string phoneNum, string nativePlace, string QQNum)
{
    this->name = name;
    this->phoneNum = phoneNum;
    this->nativePlace = nativePlace;
    this->qqNum = QQNum;
}

/**
 * 设置成员属性 
*/
void PhoneContace::modifyInfo(string name, string phoneNum, string nativePlace, string QQNum)
{
    this->name = name;
    this->phoneNum = phoneNum;
    this->nativePlace = nativePlace;
    this->qqNum = QQNum;
}