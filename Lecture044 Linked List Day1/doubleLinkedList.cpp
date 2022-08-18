#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    // constructor
    Node(int d) {

        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }

    ~Node() {

        int val = this -> data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "Memory free for node with data : " << val << endl;
        
    }

};
    
    // traversing a double linked list
void print(Node* head) {
    Node* temp = head;
    
    while (temp != NULL)
    {
        cout << temp -> data << " " ;
        temp = temp -> next;

    }cout << endl;
    
}

    // gives length of linked list
int getLength(Node* head) {
    Node* temp = head;
    int len = 0;
    
    while (temp != NULL)
    {
        len++;
        temp = temp -> next;

    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int d) {

    // empty list
    if (head == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
    }
    else { 
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d) {

    if (tail == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
    }
    
    else {
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {

    if (position == 1)
    {
        insertAtHead(head, tail,  d);
        return;
    }
    
    Node* temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
    }
    
    // inserting at last position
    if (temp -> next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }
    
    Node* nodeToInsert = new Node(d);
    
    nodeToInsert -> prev = temp;
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;


}

void deleteNode(int position, Node* &head, Node* & tail) {

    if (position == 1)
    {
        Node* temp = head;
        head = head -> next;
        temp -> next -> prev = NULL;
        temp -> next = NULL;
        delete temp;
    }

    else 
    {
        // deleting any middle node or last node

        Node* curr = head;
        Node* prev = NULL;

        int count = 1;

        while (count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }

        if (curr -> next == NULL)
        {
            tail = prev;
            curr -> prev = NULL;
            prev -> next = NULL;
        }
        
        else {
        prev -> next = curr -> next;
        curr -> next -> prev = prev;
        curr -> next = NULL;
        curr -> prev = NULL;

        delete curr;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    //cout << getLength(head) << endl;

    insertAtHead(head, tail, 11);
    print(head);
    
    insertAtHead(head, tail, 13);
    print(head);
    
    insertAtHead(head, tail, 8);
    print(head);

    insertAtTail(tail, head, 25);
    print(head);

    insertAtPosition(tail, head, 2, 100);
    print(head);
    
    insertAtPosition(tail, head, 1, 101);
    print(head);

    insertAtPosition(tail, head, 8, 102);
    print(head);

    deleteNode(1, head, tail);
    print(head);
    cout << "Head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    deleteNode(6, head, tail);
    print(head);
    cout << "Head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    deleteNode(6, head, tail);
    print(head);
    cout << "Head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    return 0;
}
