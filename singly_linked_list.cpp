#include <iostream>

using namespace std;

    class Node
    {
        public:
        
        int data;
        Node* next;
        
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
    };
    
    void insertionAtHead(Node* &Head,int d){
        Node* n = new Node(d);
        n->next = Head;
        Head = n;
    }
    
    void insertionAtTail(Node* &Head,int d){
        Node* n = new Node(d);
        Node* temp = Head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = n;
    }
    
    void insertAtPosition(Node* &Head,int d,int pos){
        Node* temp = Head;
        Node* n = new Node(d);
        Node* prev = Head;
        if(pos==1){
            n->next = temp;
            temp = n;
            Head = temp;
        }
        else{
            while(pos>1){
                prev = temp;
                temp = temp->next;
                pos--;
            }
            n->next = temp;
            prev->next = n;
        }
    }
    
    void deletion(Node* &Head,int pos){
        Node* temp = Head;
        Node* prev = Head;
        
        for(int i=0;i<pos;i++){
            if(i==0&&pos==1){
                Head = Head->next;
                delete temp;
            }
            else{
                if(i==pos-1){
                    prev->next = temp->next;
                    delete temp;
                }
                else{
                    prev = temp;
                    if(temp==NULL){
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }
    
    void print(Node* &Head){
        Node* temp = Head;
        
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

int main()
{
    Node* n = new Node(5);
    Node* Head = n;
    for(int i=4;i>0;i--){
        insertionAtHead(Head,i);
    }
    for(int i=6;i<=10;i++){
        insertionAtTail(Head,i);
    }
    print(Head);
    cout<<endl;
    deletion(Head,3);
    print(Head);
    cout<<endl;
    inserAtPosition(Head,3,3);
    print(Head);
    return 0;
}