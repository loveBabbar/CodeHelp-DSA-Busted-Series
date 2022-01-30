#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        cout<<"Memory free for "<<value<<endl;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* temp = head;
    while(temp -> next !=NULL){
        temp = temp -> next;
    }

    Node* newNode = new Node(data);
    temp->next = newNode;
    tail = temp -> next;
}

void print(Node* head) {
    if(head == NULL) {
        cout<<"No element present"<<endl;
        return;
    }

    Node* temp = head;

    do {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    } while(temp != head);

    cout<<temp->data<<endl;
}

int getLength(Node* &head) {
    Node* temp = head;
    int len = 1;

    do {
        temp = temp->next;
        len++;
    } while(temp->next != head);

    return len;
}

void split(Node* &head1, Node* &tail1, Node* &head2, Node* &tail2) {
    if(head1 == NULL || head1 -> next == NULL) return;

    tail2 = tail1;
    int len = getLength(head1);

    int mid = len / 2;
    int cnt = 1;

    Node* temp = head1;
    if(cnt != mid) {
        do {
            temp = temp -> next;
            cnt++;
        } while(cnt != mid);
    }

    if(len % 2 != 0) {
        temp = temp -> next;
    }

    tail1 = temp;
    head2 = temp -> next;

    tail1 -> next = head1;
    tail2 -> next = head2;
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 3);
    insertAtTail(head1, tail1, 4);
    insertAtTail(head1, tail1, 5);
    insertAtTail(head1, tail1, 6);

    cout<<head1 -> data <<" "<< tail1 -> data<<endl;
    tail1 -> next = head1;
    print(head1);

    Node* head2 = NULL;
    Node* tail2 = NULL;
    split(head1, tail1, head2, tail2);
    print(head1);
    print(head2);

    return 0;
}

