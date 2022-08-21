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

    while (count < position - 1)
    {
        temp = temp -> next;
        count++;
    }

    // insert tail ka pointer in the end
    if (temp -> next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    
    
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

Node* removeFromSorted(Node* &head) {

    //empty list

    if (head == NULL)
    {
        return NULL;
    }

    // non empty list

    Node* curr = head;

    while (curr != NULL)
    {
        if ((curr -> next != NULL) && curr -> data == curr -> next -> data)
        {
            Node* next_next = curr -> next -> next;
            Node* nodeToDelete = curr -> next;

            delete nodeToDelete;
            curr -> next = next_next;
        }
        
        else // not equal
        {
            curr = curr -> next;
        }
    }
    
    return head;
}

int main(int argc, char const *argv[])
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    
    print(head);

    removeFromSorted(head);
    print(head);
    
    return 0;
}
