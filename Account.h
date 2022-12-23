#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <ctime>
#include <cstdlib>

using namespace std;



class Account{
    float cash;
    public:
    float getCashBalance();
    bool setCashBalance(float cash);
    virtual  void display_transaction() = 0;

};

#endif
