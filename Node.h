#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Node{
    public:
    string name;
    int shares;
    float price;
    float total;
    Node *next;
    Node *prev;
    Node(string name,int shares,float price);
};