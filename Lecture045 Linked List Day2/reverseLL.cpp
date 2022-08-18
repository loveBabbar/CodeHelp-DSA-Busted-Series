#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

/*************************
 * Method 1 - Loop
 * ************************/
Node* reverseLL(Node* &head) {

    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    

    Node* prev = NULL;
    Node* curr = head;
    Node* forward;

    while (curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

/*****************************
 * Method 2 - Recursion
 * ***************************/

// it will return head of the reversed LL
Node* reverse1(Node* head) {

    // base case
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node* chhotaHead = reverse1(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return chhotaHead;
        
}

void reverse(Node* &head, Node* curr, Node* prev) {

    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverse(head, forward, curr);

    curr -> next = prev;
    
}


int main(int argc, char const *argv[])
{
    Node* node1 = new Node(10);

    Node* head = node1;
    reverseLL(head);
    

    return 0;
}
