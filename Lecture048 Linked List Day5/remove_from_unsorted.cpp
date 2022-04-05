// this approach will lead to TLE as the time complexity will be O(n^2) 

Node *removeDuplicates(Node *head)
{
   // O(n^2) approach
    
   // base case
    if (head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    // altleast one node is present 
    
    Node* curr = head;
    while(curr  !=NULL ){
        Node* temp = curr;
        while(temp->next != NULL){
            if(curr->data == temp ->next ->data){
                Node* next_next = temp->next->next;
                Node* nodeTodelete = temp->next;
                delete(nodeTodelete);
                temp->next = next_next;
            }
            else{
                temp = temp->next;
            }
        }
        curr= curr->next;
    }
    return head;

}

---------------------------------------------------------------------------------------------

// approach 2
  
  // Time complexity will be O(n) space complexity will be O(n)
  
 Node * removeDuplicates( Node *head) 
    {
        Node* curr = head;
        Node* prev = NULL;
        map<int,bool>m;   //   map<int,int> can also be used 
        m[curr->data]=1;
        prev = curr;
        curr=curr->next;
        while(curr != NULL){
            if(m[curr->data]){
                prev->next = curr->next;
                delete curr;
            }
            else{
                m[curr->data]=1;
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
  
