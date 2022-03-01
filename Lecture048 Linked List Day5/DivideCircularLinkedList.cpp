#include<iostream>
using namespace std;

// Dividing Circular Linked List into two halves.

class Node{

public:
    int data;
    Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

// Inserting node in a circular linked list
void insertNode(Node *&head, Node *&tail , int d){

    Node * newNode = new Node(d);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        head->next = head;
        return;
    }

    tail->next = newNode;
    tail = tail->next;
    newNode->next = head;

}

int findLen(Node *&head){

    int cnt =1;
    Node *temp = head->next;

    while(temp!=head){
        temp = temp->next;
        cnt++;
    }

    return cnt;

}

void divideLL(Node *&head,Node *&tail, int n){

    int k = n/2;
    if(n%2 != 0) k++; 

    // divide it ito first k nodes
    Node * temp = head;
    int i=1;
    while(i<k){
        temp=temp->next;
        i++;
    }

    // Storing forward node
    Node * frwd = temp->next;

    // break point and pointing it to head
    temp->next = head;

    // breaking the tail connection with head and joining it with frwd.
    tail->next = frwd; 

    print(head); // Printing 1st circular LL
    print(frwd); // Printing 2nd circulat LL

}

int main(){

    Node * head = NULL;
    Node * tail = NULL;

    insertNode(head,tail,10);
    insertNode(head,tail,9);
    insertNode(head,tail,78);
    insertNode(head,tail,19);
    insertNode(head,tail,100);
    insertNode(head,tail,7463);

    cout << head->data << endl;
    cout << tail->data << endl;

    int n= findLen(head);
    cout << n << endl; 
    
    divideLL(head,tail,n);




}