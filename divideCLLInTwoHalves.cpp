#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertNode(Node* &tail, int element, int d) {
    
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    

void print(Node* tail) {

    Node* temp = tail;

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

void deleteNode(Node* &tail, int value) {

    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        if(curr == prev) {
            tail = NULL;
        }
        else if(tail == curr ) {
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

bool isCircularList(Node* head) {
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}

Node* middleNode(Node* &tail) {
    if(tail == NULL)
        return NULL;

    Node* slow = tail;
    Node* fast = tail;

    while(fast -> next != tail) {
        fast = fast -> next;
        if(fast -> next != tail) 
            fast = fast -> next;

        slow = slow -> next;
    }

    return slow;
}

void divideLinkedListInTwoCircularLinkedList(Node* &tail, Node* &middle) {
    Node* temp1 = tail;
    Node* temp2 = middle;

    while(temp1 -> next != middle) 
        temp1 = temp1 -> next;

    temp1 -> next = tail;

    while(temp2 -> next != tail)
        temp2 = temp2 -> next;

    temp2 -> next = middle;

    cout<<"Print first Cricular Linked List : ";
    print(tail);
    cout<<"Print second circular Linked List : ";
    print(middle);
}


int main() {

    Node* tail = NULL;

    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 7, 9);
    insertNode(tail, 5, 6);
    insertNode(tail, 9, 10);
    insertNode(tail, 3, 4);
    deleteNode(tail, 5);
    insertNode(tail, 9, 10);
    insertNode(tail, 3, 4);
    insertNode(tail, 9, 10);
    insertNode(tail, 3, 4);
    

    print(tail);

    if(isCircularList(tail)) 
        cout <<"Linked List is Circular in nature"<<endl;
    else
        cout <<"Linked List is not Circular"<<endl;

    Node* middleNodee = middleNode(tail);
    cout<<"Middle Node is "<<middleNodee -> data<<endl;

    divideLinkedListInTwoCircularLinkedList(tail, middleNodee);

    return 0;
}
