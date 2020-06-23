//
//  InputStatement.hpp
//  expenditureSys
//
//  Created by Bigfish on 2020/6/14.
//  Copyright © 2020 Bigfish. All rights reserved.
//

#ifndef InputStatement_hpp
#define InputStatement_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class InputStatement
{
public:
    InputStatement();
    ~InputStatement();
    void showInputMenu();
    void inputAccount();
};

#endif /* InputStatement_hpp */
