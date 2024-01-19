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

Node<int>* solve(Node<int>* first, Node<int>* second) {
    
    //if first list has only one element
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1 -> next;
    
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2 -> next;
    
    while(next1 != NULL && curr2 != NULL) {

        if( (curr2 -> data >= curr1 -> data ) 
           && ( curr2 -> data <= next1 -> data)) {

            //insert node(curr2) between curr1 and next1
            curr1 -> next = curr2;
            next2 = curr2->next;
            curr2 -> next = next1;

            //update the pointers ( curr1 and curr2 )
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            curr1 = next1;
            next1 = next1->next;

            // if first list is fully traversed
            if(next1 ==NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    if(first -> data <= second -> data ){
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
