#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    
    //constructor 
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;

        }
    }

};


//print data of LinkedList
void print(Node* head){

    //if list is empty
    if(head == NULL){
        cout << "List is empty: " << endl;
        return;
    }

    Node* temp = head;
    do{
        cout << temp -> data << " ";
        temp = temp -> next;        
    }
    while(temp != head);
    cout << endl;

}


//function to insert node at tail
void insertAtTail(Node* &tail, int d){

    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;

}


Node* middleNode(Node* &head){

    //if one node is present
    if(head -> next == NULL) return head;

    //if 2 nodes are present 
    if(head -> next -> next == NULL) return head -> next;

    Node* fast = head -> next;
    Node* slow = head;

    while(fast != head){
        fast = fast -> next;
        if(fast != head){
            fast = fast -> next;
            
        }

        slow = slow -> next;

    }

    return slow;

}

void split2Halves(Node* &head, Node* &tail){
    
    Node* mid = middleNode(head);
    Node* head1 = head;
    Node* head2 = mid -> next;

    mid -> next = head1;
    tail -> next = head2;

    cout << "first half: ";
    print(head1);
    cout << "second half: ";
    print(head2);
    
}

int main(){

    Node* newNode = new Node(1);

    Node* head = newNode;
    Node* tail = newNode;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    // insertAtTail(tail, 6);

    //make LL to circular
    tail -> next = head;

    print(head);
    
    split2Halves(head, tail);

    return 0;
}