//
//  SearchInfo.hpp
//  expenditureSys
//
//  Created by Bigfish on 2020/6/14.
//  Copyright © 2020 Bigfish. All rights reserved.
//

#ifndef SearchInfo_hpp
#define SearchInfo_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SearchInfo
{
public:
    SearchInfo();
    ~SearchInfo();
    void showSearchMenu();
    void searchMoneyMoreThan();
    void secrchByClassID();
private:
    float totalMoney;
};

#endif /* SearchInfo_hpp */
