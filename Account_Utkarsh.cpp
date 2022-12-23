#include "Account.h"
#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

float Account::getCashBalance(){
    ifstream file;
    file.open("CashBalance.txt");
    if(!file.is_open())
    {
        cout<<"Unable to open the file."<<"CashBalance.txt"<<endl;
        return 0;
    }
    
    string line;
    while(getline(file, line))
    {
     // cout<<line;
        
    }
    cash = stod(line);
    return stod(line);
    
    file.close();
}

bool Account::setCashBalance(float cash){
  ofstream myfile;
 // myfile.open ("CashBalance.txt",std::ios_base::app);
  myfile.open ("CashBalance.txt");

  if(!myfile.is_open()){
      return false;
  }

  myfile <<cash;
  myfile.close();
  return true;
}
