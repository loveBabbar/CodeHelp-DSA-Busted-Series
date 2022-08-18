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

int getLength(Node* head) {

    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head -> next;
    }
    return len;
    
}

Node *findMiddle(Node *head) {

    int len = getLength(head);

    int ans = (len/2) +1;

    Node* temp = head;
    int count = 0;

    while (count < ans - 1)
    {
        temp = temp -> next;
        count++;
    }
    
    
    return temp;

};

Node* getMiddle(Node* head) {

    if (head == NULL || head -> next == NULL)
    {
        return head;
    
    }
    
    if (head -> next -> next == NULL)
    {
        return head -> next;
    }

    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
        }

        slow = slow -> next;
        
    }
    return slow;
    
};

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
