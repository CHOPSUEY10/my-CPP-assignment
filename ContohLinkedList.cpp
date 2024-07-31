# include <iostream>
using namespace std;

class Linked{
 
  public :
    int val;
    Linked* connect;
    // setter 
    
    int setValue(int val){
        this->val = val ;
        return val;
    }
    
    Linked* setLinks(Linked* connect){
        this->connect  = connect;
        return connect;
    }
    
    // getter
    
    int getValue() const {
        return val;
    }
    
    
    
    
};

void printLinks(Linked* print){
        
        while(print != NULL){
            cout << print->val << endl;
            
            print = print->connect;
        }
        
 }
    


void Insertback(Linked** head, int _val){
        
        Linked* newnode = new Linked();
        newnode->val = _val;
        newnode->connect = NULL;
        
        if(*head == NULL){
            *head = newnode;
            return;
        }
        
        Linked* last = *head;
        while(last->connect != NULL){
            last = last->connect;
        }
        
        last->connect = newnode;
        
        
        
        
        
      
        
    }
void Insertfront(Linked** head, int _val){
        
        
        Linked* newnode = new Linked();
        newnode->val = _val;
        newnode->connect = *head;
        
        *head = newnode;
        
        
        
    }

void DeleteElements(Linked** head, Linked** del){

    Linked* temp = new Linked();
    Linked* prev = new Linked();

    temp = *head;
    prev = *del;

    if(temp == prev){
        *head = temp->connect;
        delete temp;
        return;
    }

    while(temp->connect != prev){
        temp = temp->connect;
    }


    if(!temp) {
        return;
    }

    temp->connect = prev->connect;
    delete prev;

    





    
        
}


    

    


int main(){
    
    
    Linked* Obj1 = new Linked();
    Linked* Obj2 = new Linked();
    Linked* Obj3 = new Linked();
    
    
    Obj1->setValue(23);
    Obj1->setLinks(Obj2);
    
    Obj2->setValue(20);
    Obj2->setLinks(Obj3);
    
    Obj3->setValue(25);
    Obj3->setLinks(NULL);
    
    
    
    Insertback(&Obj1,243);
    Insertfront(&Obj1,345);
    DeleteElements(&Obj1,&Obj2);
    printLinks(Obj1);
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}