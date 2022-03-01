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
/*
https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan
*/

#include<unordered_map>

Node *removeDuplicates(Node *head)
{
    unordered_map<int,bool> mp;
    
    // If empty or single element
    if(head == NULL or head->next == NULL) return head;
    
    Node * prev = NULL;
    Node * curr = head;
    
    while(curr!=NULL){
        
        int currVal = curr->data;
        
        // Element not present
        if(mp[currVal] == 0){
            mp[currVal]++;

            prev = curr;
            // prev is now at curr 
            curr = curr->next;
            // curr is at the curr -> next
        }
        
        // If already present
        else{
            Node * toDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(toDelete);
        }
        
    }
    
    
    return head;
    
  
    
}