#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <ctime>
#include <cstdlib>
#include "StockAccount.h"
#include <unistd.h>

using namespace std;
StockAccount::StockAccount(){
    srand(time(NULL));
    int a = rand();
    if(a%2==0){
        result_index = 1;
    }
    else{
        result_index = 2;

    }
   // cout<<"Rand is"<<a;
    load_portfolio();
    cout<<endl<<"Selected file is Result_"<<result_index<<endl;

}


StockAccount::~StockAccount(){
    list.write_to_file();
    list.update_portfolio_balance(getCashBalance());
}

void StockAccount::update_total(){
    //updates the total portfolio value.
        list.update_portfolio_balance(getCashBalance());

}

void StockAccount::displayStock(string str){
    //displays transaction information by reading from Record_transaction.txt.
    float value = getValue(str);
    if(value == 0){
        cout<<endl<<"Mentioned Stock doesnt exist "<<endl;
        return;
    }
    cout<<endl<<"Company Symbol       Price Per Share\n"<<str<<"               "<<value<<endl;
}

void StockAccount::display_portfolio(){
    //Displays overall portfolio along with balance and total portfolio value
    float balance = getCashBalance();
    cout<<endl<<"\n\nPortfolio is\n\nCash Balance=$"<<balance<<endl;
    list.display(balance);
}

void StockAccount::split(string a,string arr[10]){
    //Used for string operation to split all string based on space. 

    int k =0 ;
    int i = 0;
    int flag = 1;
    
    while(i<a.length()){
      if(a[i]==' '||a[i]=='\t'){
          if(flag ==1)
          {
            k++;

          }
          flag = 0;
      } 
      else{
          flag = 1;
          arr[k] = arr[k]+a[i];
      }
      i++;
    }
}

float StockAccount::getValue(string str){
    //Reads Result or Result2 and returns the stock price of the stock requested.
    ifstream file;
    file.open("Result_"+to_string(result_index)+".txt");
    if(!file.is_open())
    {
        cout<<"Unable to open the file."<<"Result_"+to_string(result_index)+".txt"<<endl;
        return 0;
    }
    
    string line;
    float d = 0.0;
    int flag = 0;

    while(getline(file, line))
    {
      
        int i=0;
        string del,arr[3];
        split(line,arr);
        d = stof(arr[1]);
        if(arr[0].compare(str)==0){

            //d = 7;
            flag = 1;
            break;
            //return stoi(arr[1]);
            //return d;
        }        
    } 
    file.close();
    if(flag == 1){
        return d;
    }
    return 0;
}

void StockAccount::load_portfolio(){
    //This is called in contructor , it reads from result1/2.txt, 
    //portfolio.txt and creates a linked list with nodes having each stock information from previous program exit

    ifstream file;
    file.open("Portfolio.txt");
    if(!file.is_open())
    {
        cout<<"Unable to open the file. "<<"Portfolio.txt"<<endl;
        return ;
    }
    
    string line;
    while(getline(file, line))
    {
      //  cout<<line<<endl;
        

       try{
        istringstream ss(line);
        int i=0;
        string del,arr[20];
 
        while(getline(ss, del, ' ')) {
           // cout << del << '\n';
            arr[i++] =del;

        }
        float val = getValue(arr[0]);
       // cout<<"My value is"<<val;
        Node *n = new Node(arr[0],stoi(arr[1]),val);
        list.insert(n,"selectionSort");
    }
    catch(...)
    {
        cout<<endl<<"There are no stocks yet"<<endl;
    }

    }
    float balance = getCashBalance();
    file.close();

    
    
}


void StockAccount::record_transaction(string type,string stock,int shares,float price){
    //Records whenever a stock is bought or sold along with the time of the trsansaction, 
    //name, number of shares and price. It saves it in stock_transaction.txt.




    ofstream file;
    file.open("stock_transaction.txt",std::ios_base::app);
    if(!file.is_open())
    {
        cout<<"Unable to open the file. stock_transaction.txt"<<endl;
        return ;
    }

    time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);


   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);


    file<<type<<"   "<<stock<<"       "<<shares<<"      "<<price<<"        "<<shares*price<<"   "<<dt;
    file.close();

}

void StockAccount::display_transaction(){
    ifstream file;
    file.open("stock_transaction.txt");
    if(!file.is_open())
    {
        cout<<"Unable to open the file. stock_transaction.txt"<<endl;
        return ;
    }
    string line;
    while(getline(file, line)){
        cout<<line<<endl;
    }

    file.close();

}


void StockAccount::buy(string stock,int shares,string sort_type){
    float price = getValue(stock);
   // float cash =10000;
    float cash = getCashBalance();
   // cout<<price<<" "<<cash;
    if(price==0||price*shares>cash){
        cout<<"\nStock cannot be bought either because of insufficient balance or stock doesnt exist\n ";
        return;
    }
    bool b = list.update_current_list(stock,shares);

    if(b==false){
        Node *node = new Node(stock,shares,price);
        list.insert(node,sort_type);
    }
    else{
        if(sort_type.compare("bubble")==0){
            list.bubbleSort();
        }
        else{
            list.selectionSort();
        }
    }
    cout<<endl<<"You have Purchased "<<shares<<" shares of "<<stock<<" at $"<<price<<" each for a total of "<<price*shares<<endl;
   // list.display(cash-price*shares);
    b = setCashBalance(cash-price*shares);
    if(b==false){
        cout<<endl<<"Transaction couldnt be performed, Please Try Again"<<endl;
        return;
    }
    record_transaction("Buy",stock,shares,price);

}

void StockAccount::sell(string stock,int shares){
    //Buys the stock with the number given in function definition.
  //This uses list.update_current_list to make changes to already existing stock, and deletes if number of stock becomes 0

    float price = getValue(stock);
    
    float cash = getCashBalance();
    if(price==0){
        cout<<"\nMentioned stock doesnt exist\n";
        return;

    }

    bool b = list.update_current_list(stock,-shares);
    list.selectionSort();
    if(b==false){
        cout<<endl<<"Either  You are trying to  sell more shares than you own or You are trying to sell shares that you dont own"<<endl;
        return;
    }
    cout<<endl<<"You have sold "<<shares<<" shares of "<<stock<<" at $"<<price<<" each for a total of "<<price*shares<<endl;

     b = setCashBalance(cash+price*shares);
    if(b==false){
        cout<<endl<<"Transaction couldnt be performed, Please Try Again"<<endl;
        return;
    }
    record_transaction("Sell",stock,shares,price);
   // list.display(cash+price*shares);
    


}


void StockAccount::show_all_stock(){
    ifstream file;
    file.open("Result_"+to_string(result_index)+".txt");
    if(!file.is_open())
    {
        cout<<"Unable to open the file"<<endl;
        return ;
    }
    string line;
    while(getline(file, line)){
        cout<<line<<endl;
    }

    file.close();

}

 