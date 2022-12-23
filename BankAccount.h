#ifndef _BANKACCOUNT_H
#define _BANKACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <ctime>
#include <cstdlib>
#include "Account.h"
using namespace std;



class BankAccount:public Account{
    public:
    void deposit(float);
    void withdraw(float);
    void record_transaction(string,float,int,float);
    void display_transaction();
};

#endif
