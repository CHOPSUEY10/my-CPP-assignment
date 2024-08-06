# include <iostream>
# define MAX_NODE 4
using namespace std;

class Node{

    private: 

        int value; 
        Node* connect;
    public:
        // Setter
        int setValue(int value){
            this->value = value;
            return value;
        }

        Node* setNeighbor(Node* connect){
            this->connect = connect;
            return connect;
        }
        // Getter
        int getValue() const {
            return value;
        }

        Node* getNeighbor ()const {
            return connect;
        }


};


// mencetak Linked list
void printLinks(Node* print){



    while(print != NULL){
        cout << '\t' <<print->getValue() << endl;
        
        print = print->getNeighbor();
    }



}


// Melakukan operasi stack pada struktur data stack 
void StackNode(Node** head, int val_){

    int count = 0;
    Node* newnode = new Node();


    Node* sum = *head;
    while(sum->getNeighbor() != NULL){
        count++;

        sum = sum->getNeighbor();
    }

    cout << "Jumlah node : " << count + 1 << '\n' ;

    if(count >= MAX_NODE){
        
       Node* shift = *head;

       *head = shift->getNeighbor();

       delete shift;


        newnode->setValue(val_);
        newnode->setNeighbor(*head);
        *head = newnode;

        
        
       


    }
    else{

        newnode->setValue(val_);
        newnode->setNeighbor(*head);

        *head = newnode;


    }





}



int main(){

    Node* head = new Node();
    Node* Node1 = new Node();
    Node* Node2 = new Node();
    Node* Node3 = new Node();
    Node* tail = new Node();


    head->setValue(2);
    head->setNeighbor(Node1);
    Node1->setValue(4);
    Node1->setNeighbor(Node2);
    Node2->setValue(6);
    Node2->setNeighbor(Node3);
    Node3->setValue(8);
    Node3->setNeighbor(tail);
    tail->setValue(10);
    tail->setNeighbor(NULL);


    StackNode(&head,-2);
    printLinks(head);













    return 0;
}