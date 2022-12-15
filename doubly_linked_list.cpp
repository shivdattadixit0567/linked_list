#include <iostream>

using namespace std;

    class Node
    {
        public:
        
        int data;
        Node* prev;
        Node* next;
        
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
        
        ~Node(){
            cout<<"memory is free for "<<this->data<<endl;
        }
    };
    
    void insertionAtHead(Node* &Head,int d){
        Node* n = new Node(d);
        Node* temp = Head;
        if(Head==NULL){
            Head = n;
        }
        else{
            n->next = Head;
            Head->prev = n;
            Head = n;
        }
    }
    
    void insertionAtTail(Node* &Head,int d){
        Node* n = new Node(d);
        Node* temp = Head;
        
        if(Head==NULL){
            Head = temp;
        }
        else{
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
        }
    }
    
    void insertAtPosition(Node* &Head,int d,int pos){
        Node* n = new Node(d);
        Node* temp = Head;
        Node* prevtemp = Head;
        if(pos==1){
            n->next = Head;
            Head->prev = n;
            Head = n;
            return;
        }
        while(pos>1){
            prevtemp = temp;
            temp = temp->next;
            pos--;
        }
        if(temp==NULL){
            prevtemp->next = n;
            n->prev = prevtemp;
            n->next = NULL;
            return;
        }
        n->next = temp;
        temp->prev = n;
        prevtemp->next = n;
        n->prev = prevtemp;
    }
    
    void deletion(Node* &Head,int pos){
        Node* temp = Head;
        Node* prevtemp = Head;
        
        for(int i=0;i<pos;i++){
            if(i==0&&pos==1){
                Head = Head->next;
                Head->prev = NULL;
                delete temp;
            }
            else{
                if(temp->next==NULL){
                    prevtemp->next = NULL;
                    temp->prev = NULL;
                    delete temp;
                }
                else if(i==pos-1){
                    prevtemp->next = temp->next;
                    temp->next->prev = prevtemp;
                    temp->prev = NULL;
                    delete temp;
                }
                else{
                    prevtemp = temp;
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
        cout<<endl;
    }

int main()
{
    Node* Head = NULL;
    insertionAtHead(Head,10);
    print(Head);
    insertionAtHead(Head,12);
    print(Head);
    insertionAtTail(Head,13);
    print(Head);
    insertAtPosition(Head,14,4);
    print(Head);
    deletion(Head,3);
    print(Head);
    return 0;
}