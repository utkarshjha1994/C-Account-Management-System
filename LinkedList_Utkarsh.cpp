#include "LinkedList.h"

LinkedList::LinkedList(){
        head = new Node("head",-1,-1);
        tail = new Node("tail",-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void LinkedList::insert(Node *node,string sort_type){
        // Inserts a new node into linked list. 
        //Evertime a node is inserted it sorts the list based on bubble sort or selection sort


        Node *temp = tail->prev;
        temp->next = node;
        node->prev = temp;
        node->next = tail;
        tail->prev = node;
        if(sort_type.compare("bubble")==0){
            bubbleSort();
        }
        else{
            selectionSort();
        }
    }

     void LinkedList::selectionSort() {  
        Node *current = head, *index = NULL;  
        float total_temp,price_temp; 
        int share_temp;
        string name_temp;

        //Check whether list is empty  
        if(head->next == tail) {  
            return;  
        }  
        else {  
            //Current will point to head  
            for(current = head->next; current->next != tail; current = current->next) {  
                //Index will point to node next to current  
                for(index = current->next; index != tail; index = index->next) {  
                    //If current's data is greater than index's data, swap the data of current and index  
                    if(current->total < index->total) {  
                        total_temp = current->total;  
                        current->total = index->total;  
                        index->total = total_temp; 

                        price_temp = current->price;  
                        current->price = index->price;  
                        index->price = price_temp; 

                        share_temp = current->shares;  
                        current->shares = index->shares;  
                        index->shares = share_temp; 

                        name_temp .assign( current->name);  
                        current->name .assign( index->name);  
                        index->name .assign( name_temp); 
                        

                    }  
                }  
            }  
        }  
    } 


    int LinkedList::findCount(){
        // finds total number of nodes in linked list
        Node *curr = head->next;
        int count = 0;
        while(curr!=tail){
            curr = curr->next;
            count++;
        }
        return count;
    }


    void LinkedList::bubbleSort()
    // will do bubble sorting of links
    {
        Node* current;
        int i, j;
        int count =findCount();
        float total_temp,price_temp; 
        int share_temp;
        string name_temp;
    
        for (i = 0; i <= count; i++)
        {
    
            current = head->next;
            
    
            for (j = 0; j < count - i - 1; j++)
            {
    
                
                Node* index = current->next;
    
                if (current->total < index->total)
                {
                        total_temp = current->total;  
                        current->total = index->total;  
                        index->total = total_temp; 

                        price_temp = current->price;  
                        current->price = index->price;  
                        index->price = price_temp; 

                        share_temp = current->shares;  
                        current->shares = index->shares;  
                        index->shares = share_temp; 

                        name_temp .assign( current->name);  
                        current->name .assign( index->name);  
                        index->name .assign( name_temp); 
                        
    
                    /* update the link after swapping */
                    
                }
    
                current = current->next;
            }
    
            
        }
    }

    void LinkedList::write_to_file(){
        // Saves portfolio information in text file on program exit 
        ofstream file;
        file.open("Portfolio.txt");
        Node *curr  = head->next;
        string line;
        while(curr!=tail){
            line = line+curr->name+" ";
            line = line+""+to_string(curr->shares)+"\n";
            curr = curr->next;
        }
        cout<<line;
        file<<line;
        file.close();
    }

    void LinkedList::update_portfolio_balance(float cash){
        //Updates the total portfolio balance based on number of stocks, stock names and cash balance. 
        //It traverses through all the nodes and calculates total portfolio balance and saves in total_portfolio.txt


        
        time_t seconds;  
        seconds = time(NULL); 
        tm * timeinfo; 
        timeinfo = localtime(&seconds); 

         ofstream file;
        file.open("Total_portfolio.txt",std::ios_base::app);
        Node *curr  = head->next;
        string line;
        while(curr!=tail){
            cash = cash+curr->price*curr->shares;
            curr = curr->next;
            
        }
        line =to_string(cash)+","+asctime(timeinfo);

        cout<<line;
        file<<line;
        file.close();
    }

    
    
    void LinkedList::delet(string str){ // Deletes a node based on name of stock sent.
        Node *curr = head;

        while(curr!=tail&&str.compare(curr->name)!=0){
            curr = curr->next;
        }
        if(curr!=tail && str.compare(curr->name)==0){
            Node * temp = curr->prev;
            //cout<<temp;
            
            temp->next = curr->next;
            curr->next->prev = temp;
        }
    }
    
    void LinkedList::display(float balance){
        //displays all the node in the linked list
        Node *curr = head->next;
        cout<<"CompanySymbol Number PricePerShare TotalValue\n";
        while(curr!=tail){
            balance  = balance + curr->total;
            cout<<curr->name<<" "<<curr->shares<<" "<<curr->price<<" "<<curr->total<<endl;
            curr = curr->next;
        }
        cout<<"Total Portfolio Value:$"<<balance<<endl<<endl;

    }

    bool LinkedList::update_current_list(string stock,int shares){
        //If there are changes in current list as in change in number of shares of stocks, 
       // this function updates the list. If number of stocks become 0 , it also deletes. If update is not possible it returns false.


        Node *curr = head->next;
        while(curr!=tail){
            if(curr->name.compare(stock)==0){ // if stocks reduces to  0  then delete
                if(shares+curr->shares==0){
                    delet(stock);
                    return true;
                }
                else if(shares+curr->shares<0){ // user is trying to sell more stocks than he owns
                    return false;
                }
                else{
                    curr->shares = shares+curr->shares;
                    curr->total = curr->shares*curr->price;
                    return true;
                }
            }
            curr = curr->next;
        }
        return false;

    }

    