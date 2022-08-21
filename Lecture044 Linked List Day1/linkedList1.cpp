#include <iostream>
using namespace std;

class Node{
    public: 

    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    // detructor
    ~Node() {
        int value = this -> data;

        // memory free
        if (this -> next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
        
    }

};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {

    // new node create
    Node* temp = new Node(d);
    tail -> next = temp; 
    tail = tail -> next; 
}

void print(Node* &head) {

    Node* temp = head;
    
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << endl;
    
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {

    //insert at head
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    
    Node* temp = head;
    int count = 1;

    if (temp -> next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    
    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
    }

    // insert tail ka pointer in the end
    
    
    // create a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* &head) {

    // deleting first node
    if (position == 1)
    {
        Node* temp = head;
        head = head -> next;
        // memory free of start node
        // call destructor
        temp -> next = NULL;
        delete temp;
    }
    // deleting and middle node or last node
    else {

        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        
        
        prev -> next = curr -> next;

        curr -> next = NULL;
        delete curr;
    }
    
}

int main(int argc, char const *argv[])
{

    // create a new node

    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    // head pointed to node 1
    Node* head = node1;
    Node* tail = node1; 
    print(head);

    insertAtTail(tail, 12);
    print(head);
    
    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail, head, 4 , 22);
    print(head);
    
    // check the position of head and tail
    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

    deleteNode(4,head);
    print(head);

    // check the position of head and tail
    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    
    
    return 0;
}
