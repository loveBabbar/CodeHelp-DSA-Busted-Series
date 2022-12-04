#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void InsertAthead(Node *&head, int d)
{
    Node *insert = new Node(d);
    insert->next = head;
    head = insert;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


Node *solve(Node *first, Node *second)
{
    // If only 1 node is present in first list then points its next to entire second list
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // add node in bw first node
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // upadate pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            //go 1 step ahead in first list
            curr1 = next1;
            next1 = next1->next;
        }
    }

    if (next1 == NULL)
    {
        curr1->next = curr2;
    }

    return first;
}


Node *mergeList(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data <= head2->data)
    {
        return solve(head1, head2);
    }
    else
    {
        return solve(head2, head1);
    }
}


int main()
{
    Node *head1 = NULL;
    InsertAthead(head1, -1);
    InsertAthead(head1, 5);
    InsertAthead(head1, 4);
    InsertAthead(head1, 1);

    print(head1);

    Node *head2 = NULL;
    InsertAthead(head1, -1);
    InsertAthead(head2, 5);
    InsertAthead(head2, 3);
    InsertAthead(head2, 2);
    print(head2);

    print(mergeList(head1, head2));

    return 0;
}

