#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node *next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
void Insert(Node* &head,int d,int p){
    if(head==NULL){
        Node* temp= new Node(d);
        head=temp;
        temp->next=temp;
    }else if(p==1){
        Node* temp=head;
        Node *node2 = new Node(d);
        temp->next=node2;
        node2->next=temp;
        head=node2;
        /*Node* temp =head;
        while(temp->next!=head){
            temp=temp->next;
        }
        Node* newN= new Node(d);
        newN->next=head;
        temp->next=newN;
        head=newN;*/

    }else{
        Node* temp =head;
        int c=1;
        while(c<p-1){
            temp=temp->next;
            c++;
        }
        Node* newN= new Node(d);
        newN->next=temp->next;
        temp->next=newN;
    }
}
void print(Node* tail){
     if(tail==NULL){
        cout<<"List is Empty"<<endl;
     }
     else{
        Node* temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(tail!=temp); 
    cout<<endl;

     }
    
}

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Insert(head, 12,1);
    Insert(head, 5,2);
    Insert(head, 22, 3);
    Insert(head, 33, 4);
    Insert(head, 22, 5);
    print(head);
    Node* slow=head;
    Node* fast=head->next;
    Node* prev=NULL;
    while(fast->next!=head){
        fast=fast->next;
        if(fast->next!=head){
            fast=fast->next;
        }
        slow=slow->next;
    }
    cout<<slow->data<<endl;
    Node* head1=slow->next;
    fast->next=head1;
    slow->next=head;
    cout<<fast->data<<endl;
    cout<<head1->data<<endl;
    cout<<head->data<<endl;


    print(head);
    print(head1);
    cout << endl
         << head->data;

}
