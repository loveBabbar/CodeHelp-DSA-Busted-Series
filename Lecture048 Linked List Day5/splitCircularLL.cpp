/**
 * This code demonstrates how to split a circular linked list into two halves.
 * It defines a Node class for a singly linked list and provides a function to split the list.
 * The splitList function takes the head of the circular linked list as input and splits it into two halves.
 * The first half is stored in head1 and the second half is stored in head2.
 * The code then prints the original circular linked list, the first half, and the second half.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class for singly linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Function to split the circular linked list into two halves
void splitList(Node *&head, Node *&head1, Node *&head2)
{
    Node *slow = head; // Pointer to traverse the linked list one node at a time
    Node *fast = head; // Pointer to traverse the linked list two nodes at a time
    // Traverse the linked list till the fast pointer reaches the last node or the second last node
    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;       // Move the slow pointer one node ahead
        fast = fast->next->next; // Move the fast pointer two nodes ahead
    }
    head2 = slow->next; // Make the head of the second half of the linked list point to the node next to the slow pointer
    head1 = head;       // Make the head of the first half of the linked list point to the head of the original linked list
    slow->next = head1; // Make the last node of the first half of the linked list point to the head of the first half of the linked list
    // If the number of nodes in the linked list is even
    if (fast->next->next == head)
    {
        fast->next->next = head2; // Make the last node of the second half of the linked list point to the head of the second half of the linked list
    }
    // If the number of nodes in the linked list is odd
    else
    {
        fast->next = head2; // Make the last node of the second half of the linked list point to the head of the second half of the linked list
    }
}

int main()
{
    // Make a circular linked list 10 -> 20 -> 30 -> 40 -> 50
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = head;
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *temp = head;
    cout << "The original circular linked list is: ";
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
    // Calling the function to split the circular linked list into two halves
    splitList(head, head1, head2);
    temp = head1;
    cout << "The first half of the circular linked list is: ";
    while (temp->next != head1)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
    temp = head2;
    cout << "The second half of the circular linked list is: ";
    while (temp->next != head2)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
    return 0;
}
