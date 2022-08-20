#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * prev;
    node * next;

    node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }


};

int getLength(node * head){
    node *temp = head;
    int len =0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(node * &head, node* &tail, int d){

    if(head == NULL){
        node * newNode = new node(d);
        head = newNode;
        tail = newNode;
    }
    else{

        node * newNode = new node(d);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(node* &head, node * &tail, int d){
    if(head == NULL){
        node * newNode = new node(d);
        head = newNode;
        tail = newNode;
        return;
    }
    node * newNode = new node(d);
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(node * & head, node* &tail, int d, int pos){
    int len = getLength(head);
    if(pos == 1){
        insertAtHead(head, tail, d);
        return;
    }
    else if(pos-1 == len){
        insertAtTail(head, tail, d);
        return;
    }
    else{
        node * newNode = new node(d);
        node * temp = head;
        int cnt = 1;
        while(cnt<pos-1){
            cnt++;
            temp=temp->next;
        }

        // node* nxtTmp = temp->next;

        newNode->next = temp->next;
        temp->next->prev = newNode;

        temp->next = newNode;
        newNode->prev = temp;

    }
}

node * reverseDLL(node* head){
    if(head->next == NULL){
        swap(head->next, head->prev);
        return head;
    }
    node * smallHead = reverseDLL(head->next);

    swap(head->next, head->prev);  
    return smallHead;
}


void printDLL(node * head){
    node *temp = head;
    // int len =0;
    while(temp!=NULL){
        // len++;
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    node *node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtPosition(head, tail, 45, 5);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);
    insertAtTail(head, tail, 80);

    printDLL(head);

    head = reverseDLL(head);
    
    printDLL(head);

   
    return 0;
}