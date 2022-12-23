#include "BankAccount.h"



void BankAccount::withdraw(float cash){
    //Used to withdraw money in the bank account and update CashBalance.txt
    float balance = getCashBalance();
    if(balance<cash){
        cout<<endl<<"Insufficient Balance for withdrawal"<<endl;
    }
    bool b = setCashBalance(balance-cash);
    if(b==false){
        cout<<endl<<"Money Couldnt be Withdrawn, please try again "<<endl;

    }

    cout<<endl<<"$"<<cash<<" Amount Has been withdrawn";
    record_transaction("Withdraw",cash,0,balance-cash);

}


void BankAccount::deposit(float cash){
        //Used to deposit money in the bank account and update CashBalance.txt

    float balance = getCashBalance();
    bool b = setCashBalance(balance+cash);
    if(b==false){
        cout<<endl<<"Money Couldnt be deposited, please try again "<<endl;

    }

        cout<<endl<<"$"<<cash<<" Amount Has been Deposited";

    record_transaction("Deposit",cash,0,balance+cash);

}




void BankAccount::record_transaction(string type,float cash,int a,float balance){
    //Records time and date, along with type as buy or sell,total amount deposited or withdrawn in bank_transacion.txt.
    time_t seconds;  
    seconds = time(NULL); 
    tm * timeinfo; 
    timeinfo = localtime(&seconds);
    ofstream file;
    file.open("bank_transaction.txt",std::ios_base::app);
    file<<(type+" "+to_string(cash)+"         "+to_string(balance)+"          "+asctime(timeinfo));
    file.close();

}

void BankAccount::display_transaction(){
    //Displays bank account transaction from bank_transaction.txt
    ifstream file;
    cout<<endl;
    file.open("bank_transaction.txt");
    if(!file.is_open())
    {
        cout<<"Unable to open the file. bank_transaction.txt"<<endl;
        return ;
    }
    string line;
    while(getline(file, line)){
        cout<<line<<endl;
    }

    file.close();

}