#include <bits/stdc++.h>

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
// detect and remove loop in linked std::list<> ;

    // ->first method
    
    bool detectloop(Node* &Head){
        map<Node*,bool>m;
        Node* temp = Head;
        
        while(temp!=NULL){
            if(m[temp]==true){
                return 1;;
            }
            m[temp] = true;
            temp = temp->next;
        }
        return 0;
    }
    
 //  -> second method  =  floyed cycle method
 
    Node* detectLoop(Node* Head)
    {
        // your code here
        Node* slow = Head;
        Node* fast = Head;
        
        if(Head->next==NULL){
            return 0;
        }
        
        while(slow!=NULL&&fast!=NULL){
        fast = fast->next;

        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        
        if(fast==slow){
            return slow;
        }
        }
        return 0;
    }
    
    // find the starting node of loop in linked list
    
    Node* startingNode(Node* &Head){
        Node* slow = Head;
        Node* intersection = detectLoop(Head);
        
        while(slow!=intersection){
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
    
    // remove loop
    
    void removeLoop(Node* &Head){
        Node* starting = startingNode(Head);
        Node* temp = starting;
        
        while(temp->next!=starting){
            temp = temp->next;
        }
        temp->next=NULL;
    }

    int main(){
        Node* Head ;
        return 0;
    }