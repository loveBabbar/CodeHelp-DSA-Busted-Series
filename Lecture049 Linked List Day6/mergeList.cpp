/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
// Fix: Changed return type from void to Node<int>* to return the merged list head
Node<int>* solve(Node<int>* first, Node<int>* second) {
    if(first->next==NULL){   //If the next pointer of the first node is NULL, append it to the second linked list.
        first->next=second;
        return first;  // Fix: Added return statement to match the new function return type
    }
    
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    
    Node* curr2 = second;
    Node* next2 = curr2 -> next;
    
    while(next1 != NULL && curr2 != NULL) {
        
        if( (curr2 -> data >= curr1 -> data ) 
           && ( curr2 -> data <= next1 -> data)) {
            
            curr1 -> next = curr2;
            next2=curr2->next;   //Fix: Reference lost bug in Merge 2 Sorted Linked Lists
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else {     
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            
        }
        
        
    }
    
    return first;// Fix: Returning the head of the merged sorted list
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    if(first -> data <= second -> data ){
       return  solve(first, second);
    }
   else{
    return solve(second, first);
}
}
