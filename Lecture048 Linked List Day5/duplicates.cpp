/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
   	//empty List
    if(head == NULL)
        return NULL;
    
    //non empty list
    Node* curr = head;
    
    while(curr != NULL) {
        
        if( (curr -> next != NULL) && curr -> data == curr -> next -> data) {
            Node* next_next = curr ->next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else //not equal
        {
            curr = curr -> next;
        }   
    }
    
    return head; 
}

// removing duplicates from unsortedList

Node *removeDuplicates(Node *head)
{
    // Write your code here
    if( head == NULL){
        return NULL;

    }
    unordered_map< int, bool> visited;

    Node *curr = head;
    while( curr -> next != NULL){
        visited[curr -> data ] = true;

        if( visited[curr -> next -> data] == true){
            curr -> next = curr -> next -> next;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}
