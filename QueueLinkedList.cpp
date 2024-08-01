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
    
    // Enqueque 
    
  
    
    
    
    
};

  void Queue (Linked** head, int val_){
        // inisialisasi node baru yang akan dimasukkan pada akhir list (tail)
        Linked* newnode = new Linked();
        newnode->val = val_;
        newnode->connect = NULL;
        // jika list hanya ada satu node maka lakukan ini
        if(*head == NULL){
            *head = newnode;
            delete *head;
            return;
        }
        
        // Enqueue(Memasukkan node baru pada akhir list / tail)
       Linked* Enqueue = *head;
       while(Enqueue->connect != NULL){
           Enqueue = Enqueue->connect;
       }
       Enqueue->connect = newnode;
       // Dequeue(Mengeluarkan head dari list lalu menjadikan node selanjutnya sebagai head)
       Linked* Dequeue = *head;
       *head  = Dequeue->connect;
       delete Dequeue;
    }
    
    void printLinks(Linked* print){
        
        while(print != NULL){
            cout << print->val << endl;
            
            print = print->connect;
        }
        
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
    
    //printLinks(Obj1);
    printLinks(Obj1);
    Queue(&Obj1,90); 
    cout << endl;
    printLinks(Obj1);
    
    
    
 
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}