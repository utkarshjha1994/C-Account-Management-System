
Brief Description of the Project


Account Management system manages a stock portfolio account and a bank account. User has a Bank account and a Stock account. User can deposit the cash into bank account. Initially user has 10000$ in his bank account and he uses it to buy new stocks from the market.He can buy and sell the stock which affects his account balance. With changing time the value of stocks changes and total portfolio value , which is sum of stocks value and account balance, vary with the time.
Account Management system handles all this these things.

To implement the system Account class is created which has  2 inherited class as StockAccount and BankAccount. StockAccount Manages the stock information of then user which includes the stocks user own and its number. All the important informations are stored in text files and it changes dynamically based on program execution.

Similarly BankAccount class ensures deposit or withdrawal of the money. Total account balance is maintained in a text file. With deposit account balance is changes positively and with withdraw account balance is reduced.All the transaction are recorded with time stamp. 

There are couple of functions common to both the class and is implemented in Account class. 
Prime data structure used in the project is Doubly linked list which stores stock portfolio information. LinkedList class is implamenented for the same. Node class is implemented to store information of each stock.Linked List is sorted all the time.

Finally Graph was implemented using R . Please find further information below.






Technology used for Graph.


I used R to draw graphs . I used ggplot2 time series to plot variation in total portfolio value. I read the values from Total_portfolio.txt to plot the result. I wrote the code and saved it in graph.R.

In C++ I ran the script graph.R using System(RSCRIPT,filename) and then the result gets stored in RPlots.pdf and it gets open and shows the result. You can go back to program and continue the execution after the graph is displayed.
























Text Files Used

•	CashBalance.txt – This dynamically updates the account balance of the user based on selling, buying, depositing ,withdrawing.
•	Portfolio.txt – This stores the stock name and number of shares owned by the user . This stores information when program exits.It dynamically updates if stocks are bought or sold.
•	Total_portfolio.txt  - This updates the total portfolio balance along with date and time. This is used in plot to check the variation of Total Portfolio balance.
•	stock_transaction.txt -  It stores all stock transaction with all transactions related information of buying or selling stocks and also transaction time.
•	bank_transaction.txt – It stores all the transaction information related to bank account.It stores all the deposit , withdraw , total amount ,updated balance and transaction time.

CPP files used

•	LinkedList_Utkarsh.cpp – used for LinkedList.h class file.
•	Node_Utkarsh.cpp – used for Node.h class file.
•	Account_Utkarsh.cpp – Used for Account.h class file.
•	StockAccount_Utkarsh.cpp – Used for StockAccount.h class file.
•	Bank_Account.cpp_Utkarsh – Used for Bank Account.h class file
•	Main_Utkarsh.cpp – Used to implement main functions











Classes used and Function inside the classes


				Account class 
•	This is the base class which only has Cash only has attribute. This is an abstract class and it has 2 derived class.It stores the account balance and below are functions implemented .


Functions
•	getCashBalance() – its gets account balance from CashBalance.txt and updates the Cash attribute.
•	setCashBalance(float) – It sets account balance and saves it CashBalance.txt
•	display_tranjsaction is a virtual function and each of the derived function has its own definition of it.



Node Class

•	Attributes- name ,shares, price,total,next,prev

Name – Used to store stock name
Shares – stores number of stock shares
Price – it stores price of stock
Total – it stores  total value of stock as shares*price.









Linked List Class

This is implementation of doubly linked list data structure and used to store portfolio information. Each element is part of node class.
Attribute of this class are head of the node class which is top of the class and tail which is back end of the linked list

Functions:

•	Insert – Inserts a new node into linked list. Evertime a node is inserted it sorts the list based on bubble sort or selection sort
•	Delet -  Deletes a node based on name of stock sent.
•	Bubble_sort – Sorts list based on total value in bubble sort.
•	Selection_sort - Sorts list based on total value in Selection sort.
•	Update_current_list -  If there are changes in current list as in change in number of shares of stocks, this function updates the list. If number of stocks become 0 , it also deletes. If update is not possible it returns false.
•	Display – displays all the node in the linked list
•	Delet – deletes a node
•	Update_portfolio_balance  - Updates the total portfolio balance based on number of stocks, stock names and cash balance. It traverses through all the nodes and calculates total portfolio balance and saves in total_portfolio.txt
•	Write_to_file – It updates the portfolio information from all node into portfolio.txt when program exits.











StockBalance Class


This class manages all the information regarding stock including buying or selling information. It inherits account class.


Attributes –
•	List – This is of Linked List type and stores all portfolio information in sorted order in nodes.
•	Result_index – This is either 1 or 2 randomly generated by rand(), to select result_1.txt or result_2.txt


Functions – 
•	Load_portfolio – This is called in contructor , it reads from result1/2.txt, portfolio.txt and creates a linked list with nodes having each stock information from previous program exit.
•	Update_total – updates the total portfolio value.
•	Check_stock – checks if the  particular stock exists.
•	Buy – Buys the stock with the number given in function definition.This uses list.update_current_list to make changes to already existing stock, otherwise uses list.insert to insert a new one.
•	Sell – works similar to buy, just here we are selling the stock.
•	Record_transaction – Records whenever a stock is bought or sold along with the time of the trsansaction, name, number of shares and price. It saves it in stock_transaction.txt.
•	Display_transaction – displays transaction information by reading from Record_transaction.txt.
•	Display_stock – Displays stock price  requested from result1/2.txt .
•	getValue – Reads Result or Result2 and returns the stock price of the stock requested.
•	Display_portfolio  - Displays overall portfolio along with balance and total portfolio value
•	Split – Used for string operation to split all string based on space. 
•	Show_all_stocks – Shows all the stock information in the market from Result_1.txt or Result_2.txt


BankAccount Class

This is used to manage bank or cash balance of the user. User can withdraw or deposit the money to the bank account. It inherits account class.

Functions
•	Deposit – Used to deposit money in the bank account and update CashBalance.txt
•	Withdraw – Used to withdraw money from CashBalance.txt
•	Record_transaction – Records time and date, along with type as buy or sell,total amount deposited or withdrawn in bank_transacion.txt.
•	Display_transaction – Displays bank account transaction from bank_transaction.txt
















      
How to run the code in cmd or terminal

g++ Node.h Node_Utkarsh.cpp LinkedList.h LinkedList_Utkarsh.cpp Account.h Account_Utkarsh.cpp StockAccount.h StockAccount_Utkarsh.cpp BankAccount.h BankAccount_Utkarsh.cpp main_Utkarsh.cpp

./a.out

Extra Features:
1.	I have implamented both selection sort and bubble sort design features
2.	I have implemented a feature which displays  all the stock information from either result1.txt or result2.txt






















Output

(base) utkarshjha@Utkarshs-MacBook-Pro Project % g++ Node.h Node_Utkarsh.cpp LinkedList.h LinkedList_Utkarsh.cpp Account.h Account_Utkarsh.cpp StockAccount.h StockAccount_Utkarsh.cpp BankAccount.h BankAccount_Utkarsh.cpp main_Utkarsh.cpp
clang: warning: treating 'c-header' input as 'c++-header' when in C++ mode, this behavior is deprecated [-Wdeprecated]
clang: warning: treating 'c-header' input as 'c++-header' when in C++ mode, this behavior is deprecated [-Wdeprecated]
clang: warning: treating 'c-header' input as 'c++-header' when in C++ mode, this behavior is deprecated [-Wdeprecated]
clang: warning: treating 'c-header' input as 'c++-header' when in C++ mode, this behavior is deprecated [-Wdeprecated]
clang: warning: treating 'c-header' input as 'c++-header' when in C++ mode, this behavior is deprecated [-Wdeprecated]
(base) utkarshjha@Utkarshs-MacBook-Pro Project % ./a.out
Welcome to the Account Management System

1.Stock Portfolio Account
2.Bank Account
3.Exit
Enter your choice 1

Selected file is Result_2

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 8
GOOG	568.964	11/18/2010
MSFT	30.62	11/18/2010
YHOO	16.38	11/18/2010
AAPL	197.92	11/18/2010
GS	168.01	11/18/2010
DIS	31.01	11/18/2010
GE	16.59	11/18/2010
AIG	32.10	11/18/2010
AMZN	132.66	11/18/2010
IBM	130.96	11/18/2010
BA	52.70	11/18/2010
CSCO	24.46	11/18/2010
HPQ	21.04	11/18/2010
DELL	16.29	11/18/2010
HD	28.18	11/18/2010
AMD	5.95	11/18/2010
XOM	75.38	11/18/2010
ENER	11.57	11/18/2010
EMC	18.04	11/18/2010
FNM	2.02	11/18/2010
FRE	2.14	11/18/2010
WFC	26.87	11/18/2010
HAL	28.88	11/18/2010
INTC	20.24	11/18/2010
RIMM	60.72	11/18/2010
JAVA	9.61	11/18/2010
JPM	41.46	11/18/2010
KO	58.48	11/18/2010
KSS	52.96	11/18/2010
KFT	26.18	11/18/2010
SLB	64.34	11/18/2010
MER	12.78	11/18/2010
LMT	77.10	11/18/2010
DAL	6.62	11/18/2010
MET	32.90	11/18/2010
NCC	1.20	11/18/2010
NVDA	13.90	11/18/2010
USO	37.42	11/18/2010
PFE	19.36	11/18/2010
PG	62.80	11/18/2010
QI	0.15	11/18/2010
RBS	12.99	11/18/2010
ADBE	36.81	11/18/2010
TWX	32.64	11/18/2010
TGT	48.46	11/18/2010
USB	24.29	11/18/2010
VLO	18.47	11/18/2010
VMW	41.96	11/18/2010
XRX	4.83	11/18/2010

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 1

Please enter the stock symbol :GOOG

Company Symbol       Price Per Share
GOOG               568.964

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 3

Please Enter the stock symbol you wish to purchase :GOOG

Enter the maximum amount you are willing to pay: $100

Stocks cant be bought with the amount you entered, please raise your stakes

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 3

Please Enter the stock symbol you wish to purchase :GOOG

Enter the maximum amount you are willing to pay: $590

Please Enter the number of shares :8

Select Sorting type 1.Selection Sort 2. Bubble Sort2

You have Purchased 8 shares of GOOG at $568.964 each for a total of 4551.71

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 3

Please Enter the stock symbol you wish to purchase :AMZN

Enter the maximum amount you are willing to pay: $200

Please Enter the number of shares :4

Select Sorting type 1.Selection Sort 2. Bubble Sort1

You have Purchased 4 shares of AMZN at $132.66 each for a total of 530.64

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 2



Portfolio is

Cash Balance=$4917.65
CompanySymbol Number PricePerShare TotalValue
GOOG 8 568.964 4551.71
AMZN 4 132.66 530.64
Total Portfolio Value:$10000


Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 4

Please Enter the stock symbol you wish to sell :GOOG

Please Enter the number of shares :3

You have sold 3 shares of GOOG at $568.964 each for a total of 1706.89

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 2



Portfolio is

Cash Balance=$6624.54
CompanySymbol Number PricePerShare TotalValue
GOOG 5 568.964 2844.82
AMZN 4 132.66 530.64
Total Portfolio Value:$10000


Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 3

Please Enter the stock symbol you wish to purchase :Dell

Enter the maximum amount you are willing to pay: $200

Mentioned Stocks doesnt exist 

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 3       

Please Enter the stock symbol you wish to purchase :DELL

Enter the maximum amount you are willing to pay: $200

Please Enter the number of shares :10

Select Sorting type 1.Selection Sort 2. Bubble Sort1

You have Purchased 10 shares of DELL at $16.29 each for a total of 162.9

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 2



Portfolio is

Cash Balance=$6461.64
CompanySymbol Number PricePerShare TotalValue
GOOG 5 568.964 2844.82
AMZN 4 132.66 530.64
DELL 10 16.29 162.9
Total Portfolio Value:$10000


Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 3

Please Enter the stock symbol you wish to purchase :SLB

Enter the maximum amount you are willing to pay: $1000

Please Enter the number of shares :20

Select Sorting type 1.Selection Sort 2. Bubble Sort1

You have Purchased 20 shares of SLB at $64.34 each for a total of 1286.8

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 2



Portfolio is

Cash Balance=$5174.84
CompanySymbol Number PricePerShare TotalValue
GOOG 5 568.964 2844.82
SLB 20 64.34 1286.8
AMZN 4 132.66 530.64
DELL 10 16.29 162.9
Total Portfolio Value:$10000


Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 7
GOOG 5
SLB 20
AMZN 4
DELL 10
10000.000000,Fri Dec 23 12:02:08 2022

1.Stock Portfolio Account
2.Bank Account
3.Exit
Enter your choice 1

Selected file is Result_2

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 7
GOOG 5
SLB 20
AMZN 4
DELL 10
10000.000000,Fri Dec 23 12:02:22 2022

1.Stock Portfolio Account
2.Bank Account
3.Exit
Enter your choice 1

Selected file is Result_2

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 7
GOOG 5
SLB 20
AMZN 4
DELL 10
10000.000000,Fri Dec 23 12:02:30 2022

1.Stock Portfolio Account
2.Bank Account
3.Exit
Enter your choice 1

Selected file is Result_2

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 7
GOOG 5
SLB 20
AMZN 4
DELL 10
10000.000000,Fri Dec 23 12:02:36 2022

1.Stock Portfolio Account
2.Bank Account
3.Exit
Enter your choice 1

Selected file is Result_1

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 5
9953.000000,Fri Dec 23 12:04:15 2022
Warning message:
package ‘ggplot2’ was built under R version 4.1.2 

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 5
9953.000000,Fri Dec 23 12:06:10 2022
Warning message:
package ‘ggplot2’ was built under R version 4.1.2 

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 7
GOOG 5
SLB 20
AMZN 4
DELL 10
9953.000000,Fri Dec 23 12:06:51 2022

1.Stock Portfolio Account
2.Bank Account
3.Exit
Enter your choice 2

 Please select an option: 
1. View account balance
2. Deposit money
3. Withdraw money 
4. Print out history
5. Return to previous menu Enter your choice 2

Enter amount to deposit 1000

$1000 Amount Has been Deposited
 Please select an option: 
1. View account balance
2. Deposit money
3. Withdraw money 
4. Print out history
5. Return to previous menu Enter your choice 2

Enter amount to deposit 200

$200 Amount Has been Deposited
 Please select an option: 
1. View account balance
2. Deposit money
3. Withdraw money 
4. Print out history
5. Return to previous menu Enter your choice 4

Type         Amount           Balance                  Date
Deposit 1000.000000         6174.839844          Fri Dec 23 12:07:00 2022
Deposit 200.000000         6374.839844          Fri Dec 23 12:07:10 2022

 Please select an option: 
1. View account balance
2. Deposit money
3. Withdraw money 
4. Print out history
5. Return to previous menu Enter your choice 5

1.Stock Portfolio Account
2.Bank Account
3.Exit
Enter your choice 1

Selected file is Result_1

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 2



Portfolio is

Cash Balance=$6374.84
CompanySymbol Number PricePerShare TotalValue
GOOG 5 569.964 2849.82
SLB 20 63.34 1266.8
AMZN 4 129.66 518.64
DELL 10 14.29 142.9
Total Portfolio Value:$11153


Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 5
11153.000000,Fri Dec 23 12:08:18 2022
Warning message:
package ‘ggplot2’ was built under R version 4.1.2 

Please select an option:
1. Display the price for a stock symbol
2. Display the current portfolio
3. Buy shares
4. Sell shares
5. View a graph for the portfolio value
6. View transaction history 
7. Return to previous menu
 8. Show all stock information
Enter your choice 7
GOOG 5
SLB 20
AMZN 4
DELL 10
11153.000000,Fri Dec 23 12:10:41 2022

1.Stock Portfolio Account
2.Bank Account
3.Exit
Enter your choice 3
(base) utkarshjha@Utkarshs-MacBook-Pro Project % 




















 
















![image](https://user-images.githubusercontent.com/24908130/209396936-a2f39e43-e23c-4fdf-9210-42819fe3aa35.png)
