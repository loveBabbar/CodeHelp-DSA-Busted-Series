#include<iostream>
#include<map>
using namespace std;


class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
    }
};

void insertNode(Node* &tail,int data) {
    Node* newNode = new Node(data);

    if(tail==NULL) {
        newNode->next = newNode;
        tail=newNode;
    }else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return ;
}

void printLoop(Node* head) {
    Node* temp = head;
    do{
         cout<<temp->data<<" "; 
        temp= temp->next;
       
        
    }while(temp!=head);
    cout<<endl;
}


Node* divideHalf(Node* head) {

    if(head==NULL) {
        return NULL;
    }
    Node* slow=head;
    Node* fast = head;
    Node* head2;

    while(fast->next!=head) {
        slow= slow->next;
        fast= fast->next;
        if(fast->next!=head) {
            fast = fast->next;
        }
    }
    head2 = slow->next;
   fast-> next  = head2;
   slow->next = head;


   return head2;
}














int main() {


    Node* tail = NULL;
    Node* head = NULL;

    insertNode(tail,10);
    insertNode(tail,20);
    insertNode(tail,30);
    insertNode(tail,40);
    insertNode(tail,50);
    insertNode(tail,60);
    insertNode(tail,70);
    head = tail->next;
    printLoop(head);
    Node* head2 = divideHalf(head);
     printLoop(head);
      printLoop(head2);
    return 0;
}