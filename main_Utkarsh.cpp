#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <ctime>
#include <cstdlib>
#include "StockAccount.h"
#include "BankAccount.h"





void stock(){
    StockAccount account;

    int a;
    for(;;){
        cout<<"\nPlease select an option:\n1. Display the price for a stock symbol\n2. Display the current portfolio\n3. Buy shares\n4. Sell shares\n5. View a graph for the portfolio value\n6. View transaction history \n7. Return to previous menu\n 8. Show all stock information\n";
        cout<<"Enter your choice ";
        cin>>a;
        switch(a){
            case 1:{
                string stock;
                cout<<endl<<"Please enter the stock symbol :";
                cin>>stock;
                account.displayStock(stock);
                break;
            }
            case 2:{
                account.display_portfolio();
                break;
            }
             case 3:{
                string stock;
                cout<<"\nPlease Enter the stock symbol you wish to purchase :";
                cin>>stock;
                float max;
                cout<<"\nEnter the maximum amount you are willing to pay: $";
                cin>>max;
                int i = account.getValue(stock);
                if(i==0){
                    cout<<endl<<"Mentioned Stocks doesnt exist "<<endl;
                    break;
                }
                if(max<i){
                    cout<<endl<<"Stocks cant be bought with the amount you entered, please raise your stakes"<<endl;
                    break;
                }
                
                cout<<endl<<"Please Enter the number of shares :";
                int shares;
                cin>>shares;
                int sort;
                cout<<endl<<"Select Sorting type 1.Selection Sort 2. Bubble Sort";
                cin>>sort;

                if(sort == 1){
                    account.buy(stock,shares,"Selection");
                }
                else if(sort==2){
                    account.buy(stock,shares,"bubble");

                }

                
                break;
            }
            
            case 4:{

                string stock;
                cout<<"\nPlease Enter the stock symbol you wish to sell :";
                cin>>stock;
                cout<<endl<<"Please Enter the number of shares :";
                int shares;
                cin>>shares;
                account.sell(stock,shares);
                break;
            }
            case 5:{
                account.update_total();
                string r_command = "RScript \"graph.R\"" ;
                system(r_command.c_str());

                system("open -a Preview Rplots.pdf");
                

                break;
            }
            case 6:{
                account.display_transaction();
                break;
            }
            case 7:{
                return;
                break;
            }
            case 8:{
                account.show_all_stock();
            }

        }

    }
}

void bank(){
    int a;
    BankAccount account;
    for(;;){
       cout<<"\n Please select an option: \n1. View account balance\n2. Deposit money\n3. Withdraw money \n4. Print out history\n5. Return to previous menu ";
       cout<<"Enter your choice ";
       cin>>a;
       switch(a){
           case 1:{
               cout<<"\nYou have $"<<account.getCashBalance()<<" in your account\n";
            break;
           }
           case 2:{
               cout<<"\nEnter amount to deposit ";
               float cash;
               cin>>cash;
               account.deposit(cash);
               break;
           }
           case 3:{
               cout<<"\nEnter amount to withdraw ";
               float cash;
               cin>>cash;
               account.withdraw(cash);
               break;
           }
           case 5:{
               return;
           }
           case 4:{
               account.display_transaction();
               break;
           }

           

       }

    }
}







int main()
{
    int a;
    cout<<"Welcome to the Account Management System\n";
    for(;;){
        cout<<"\n1.Stock Portfolio Account\n2.Bank Account\n3.Exit\n";
        cout<<"Enter your choice ";

        cin>>a;

        switch(a){
            case 1:{
                stock();
                break;
            }
            case 2:{
                bank();
                break;
            }
            case 3:{
                return 0;
            }
            default:{
                cout<<endl<<"Enter the correct keys";
                break;
            }
        }
    }






  
    return 0;
}
