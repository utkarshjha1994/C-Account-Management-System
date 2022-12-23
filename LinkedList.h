#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <ctime>
#include <cstdlib>
#include "Node.h"
using namespace std;


class LinkedList{
    Node *head;
    Node *tail;
    public:
    LinkedList();
    void insert(Node *node,string sort_type);
    void selectionSort();
    void bubbleSort();
    int findCount();
    void write_to_file();
    void update_portfolio_balance(float cash);
    void delet(string str);
    void display(float balance);
    bool update_current_list(string stock,int shares);
};