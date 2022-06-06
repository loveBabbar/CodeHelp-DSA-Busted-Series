#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
}
*first = NULL;

void create(int arr[], int n){
    int i;
    Node *t, *last;
    first = new Node;    // creates a new node and first will be pointing on that one
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL; 
        last->next = t;
        last = t;
    }
    
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

Node* removeDuplicatesSortedLL(Node* head)
{
    if(head == NULL)
    return NULL;

    Node* curr = head;

    while(curr->next != NULL)
    {
        if((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node* next_next = curr->next->next;
            delete curr->next;
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

Node *removeDuplicatesUnsortedLL(Node *head)
{
    // Write your code here
    if(head == NULL)
        return NULL;
    
    Node* curr = head;
    
    while(curr != NULL)
    {
        Node* temp = curr;
        while(temp->next != NULL)
        {
            if(curr->data == temp->next->data)
            {
                Node* next_next = temp->next->next;
                delete (temp->next);
                temp->next = next_next;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}


int main(){

    // int A[] = {3,3,5,5,8,8,8,9,9};
    int A[] = {1,2,1,2,2,2,7,7};

    create(A, 8);

    // removeDuplicatesSortedLL(first);
    removeDuplicatesUnsortedLL(first);

    display(first);

    return 0;
}
