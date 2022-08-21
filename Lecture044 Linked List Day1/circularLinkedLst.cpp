#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // construtor

    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }

    ~Node() {
        int value = this ->data;
        if (this -> next != NULL)
        {
            delete next;
            next = NULL;

        }
        cout << "Memory is free for node with data " << value << endl; 
        
    }

};

void insertNode(Node* &tail, int element, int d) {

    // assuming that the element is present n the list

    // empty list
    if (tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;

    }
    // non empty list
    else
    {
        Node* curr = tail;

        while (curr -> data != element)
        {
            curr = curr -> next;

        }

        // element found -> curr is representing that element
        
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
    
}

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if (tail == NULL)
    {
        cout << " list is empty" << endl;
        return;
    }
    
    cout << tail -> data << " ";
    
    while (tail -> next != temp)
    {
        tail = tail -> next;
        cout << tail -> data << " ";
    }cout << endl;
    
}

void deleteNode(Node* &tail, int value) {
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty. Please check again " << endl;

    }

    else 
    {
        // non empty
        // assuming that "value" is present in the linked list

        Node* prev = tail;
        Node* curr = prev -> next;

        while (curr -> data != value)
        {
            prev = curr;
            curr = curr -> next;
        }
        
        prev -> next = curr -> next;

        // delete 1 node LL

        if (curr == prev)
        {
            tail = NULL;
        }
        

        else if (tail == curr)
        {
            tail = prev;
        }
        
        curr -> next = NULL;

        delete curr;
    }
    
}

int main(int argc, char const *argv[])
{
    Node* tail = NULL;

    // empty list main insert kr rhe hain
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    /*insertNode(tail, 5, 7);
    print(tail);
    
    insertNode(tail, 7, 9);
    print(tail);
    
    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);
    
    insertNode(tail, 3, 4);
    print(tail); */
    
    deleteNode(tail, 5);
    print(tail); 

    return 0;
}
