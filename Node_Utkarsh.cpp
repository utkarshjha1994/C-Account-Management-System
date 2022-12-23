#include "Node.h"


Node::Node(string name,int shares,float price){
        this->name.assign(name);
        this->shares = shares;
        this->price = price;
        this->total = this->shares*this->price;
    }