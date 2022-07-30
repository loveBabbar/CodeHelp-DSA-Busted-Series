#include<bits/stdc++.h>

/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL)
        return head;
        
    unordered_map<int,bool> visited;
    Node *temp=head;
    Node *prev=NULL;
    while(temp)
    {
        if(visited[temp->data]){
            prev -> next = temp -> next;
            delete(temp);
        }
        else{
            visited[temp->data]=true;
            prev=temp;
        }
        temp=prev->next;
    }
    return head;
}