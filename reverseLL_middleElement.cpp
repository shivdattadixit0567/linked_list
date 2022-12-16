#include <iostream>
using namespace std;

    class Node
    {
        public : 
        int data;
        Node* next;
        
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
    };
    
    void insertionAtHead(Node* &Head,int d){
        Node* n = new Node(d);
        
        if(Head==NULL){
            Head = n;
        }
        else{
            n->next = Head;
            Head = n;
        }
    }
    
    void print(Node* &Head){
        Node* temp = Head;
        
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    
    void reverse(Node* &Head){
        Node* curr = Head;
        Node* prev = NULL;
        Node* temp = NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        Head = prev;
    }
    
    int middle_element(Node* &Head){
        Node* temp = Head;
        Node* prev = Head;
        int ct = 0;
        while(temp!=NULL){
            ct++;
            temp = temp->next;
        }
        ct = ct/2;
        while(ct--){
            prev = prev->next;
        }
        return prev->data;
    }

    int main()
{
    Node* Head = NULL;
    
    insertionAtHead(Head,5);
    insertionAtHead(Head,4);
    insertionAtHead(Head,3);
    insertionAtHead(Head,2);
    insertionAtHead(Head,1);
    
    print(Head);
    cout<<endl;
    reverse(Head);
    print(Head);
    cout<<endl;
    cout<<middle_element(Head)<<endl;
    cout<<endl;
    cout<<middle_element(Head)<<endl;    

    return 0;
}