# include <iostream>
using namespace std;
// DOUBLY LINKED LIST
class Node {
  
  protected :
    // atribut dari masing masing node
    int value;
    Node* Next;
    Node* Prev;
    
    public :
    // setter 
        int setValue(int value){
            this-> value = value;
            return value;
        }
        
        Node* setNextNode(Node* Next){
            this-> Next = Next;
            return Next;
        }
    
        Node* setPrevNode(Node* Prev){
            this-> Prev = Prev;
            return Prev;
        }
        // getter 
        int getValue() const{
            return value;
        }
        
        Node* getNextNode() const {
            return Next;
        }
    
        Node* getPrevNode(){
            return Prev;
        }

        // Menghapus secara otomatis node object jika program telah dijalankan
        ~Node(){
            delete  Next;
            delete  Prev;
        }
    
    
};


        
        // operation
    void insertfront(Node** head, int val){ // menambahkan node pada bagian depan dari linked list
            
        Node* newnode = new Node(); 
   
        
        newnode->setValue(val); // 
        newnode->setPrevNode(nullptr);
        newnode->setNextNode(*head);
        
        if (*head != nullptr) { // jika tidak ada node sama sekali maka jalankan ini
            (*head)->setPrevNode(newnode);
        }
        
        *head = newnode;    // set by reference
            
            
    }
        
    void insertback(Node** head, int val){ // menambahkan node pada bagian belakang dari linked list
        
        Node* newnode = new Node();
        newnode->setValue(val);
        newnode->setNextNode(nullptr);
        
        
        if (*head == nullptr) { // jika tidak ada node sama sekali maka jalankan ini 
            newnode->setPrevNode(nullptr);
            *head = newnode;
            return;
        }
    
        Node* tranverser = *head; 
        while(tranverser->getNextNode() != nullptr){ // mencari tail dari linked list
            tranverser = tranverser->getNextNode();
            
        }
        
        
        
        // memasukkan node baru sebagai bagian dari linked list
        tranverser->setNextNode(newnode); 
        newnode->setPrevNode(tranverser);
        
            
            
            
    }
    
    
    
    void Printforward(Node* head){
        Node* tranverser = head;
        while(tranverser != nullptr){
            cout << tranverser->getValue() << endl;
            tranverser = tranverser->getNextNode();
        }
        
    } 
    
        
    void Printbackward(Node* tail){
        Node* tranverser = tail;
        while(tranverser != nullptr){
            cout << tranverser->getValue() << endl;
            tranverser = tranverser->getPrevNode();
        }
        
    } 
    
    
    
    
    


int main(){
    
   
    
    Node* node = new Node();
    node->setValue(4);
    node->setPrevNode(nullptr);
    node->setNextNode(nullptr);
    
    Node* head = node;
   
    
    insertfront(&head,2);
    insertfront(&head,6);
    insertback(&head,8);
    Printforward(head);

    Node* tail = head;
        while(tail->getNextNode() != nullptr){
            tail = tail->getNextNode();
    }

    Printbackward(tail);
        

    
    
    
    
    
    
}