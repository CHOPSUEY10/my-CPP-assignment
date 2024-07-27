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
    printLinks(Obj1);
    
    
    delete Obj1, Obj2, Obj3;
    
    
    
    
    
    
    
    
    return 0;
}