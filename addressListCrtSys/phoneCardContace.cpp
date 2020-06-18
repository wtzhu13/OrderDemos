#include "phoneCardContace.h"

/**
 * 构造函数 
*/
PhoneCardContace::PhoneCardContace(string name, string phoneNum)
{
    this->name = name;
    this->phoneNum = phoneNum;
}

/**
 * 析构函数 
*/
PhoneCardContace::~PhoneCardContace()
{
}

/**
 * 设置成员属性 
*/
void PhoneCardContace::setInfo(string name, string phoneNum)
{
    this->name = name;
    this->phoneNum = phoneNum;
}

/**
 * 设置成员属性 
*/
void PhoneCardContace::modifyInfo()
{
    
}

