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

// Naive Approach  in Time Complexity - O(N^2)

Node *removeDuplicates(Node *head)
{
    
    if(head == NULL) return NULL;
    Node* curr = head;
    
    while(curr != NULL && curr -> next != NULL){
        Node* temp = curr ;
            while(temp -> next != NULL)
            {
                if(curr -> data == temp -> next -> data){
                    Node* duplicate = temp -> next;
                    temp -> next = temp -> next -> next;
                    delete(duplicate);
                }
                else{
                    temp = temp -> next;
                }
         }
        
        curr = curr -> next;
    }
    
 return head;
}

//Time Complexity - O(N^2)
//Space Complexity - O(1)






// Optimised Approach using Map

/****************************************************************
    head
    prev    curr
    2       2             3 4  4  5
*****************************************************************/
#include <bits/stdc++.h> 
Node *removeDuplicates(Node *head)
{
    if (head == NULL) return NULL;
    map <int , bool> visited;
    
    Node* prev = head;
    Node* curr = head -> next;
    
    visited[prev-> data] = true;
    while (curr != NULL)
    {
           if (visited[curr -> data] == true)
           {
                prev -> next = curr -> next;
                delete (curr);

            }
            else 
            {
                visited[curr -> data]  =  true;
                prev = prev -> next;
            }
        
    curr = prev -> next;
    }
    
return head;
}


//Time Complexity - O(N)
//Space Complexity - O(N)
