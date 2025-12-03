Node<int>* solve(Node<int>* first, Node<int>* second) {

    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;

    Node<int>* curr2 = second;
    Node<int>* next2 = NULL;

    // Traverse while both lists still have elements
    while (curr1 != NULL && next1 != NULL && curr2 != NULL) {

        // curr2 fits between curr1 and next1
        if (curr2->data >= curr1->data && curr2->data <= next1->data) {
            
            next2 = curr2->next;   // save next of second list
            
            // insert curr2 between curr1 and next1
            curr1->next = curr2;
            curr2->next = next1;

            // move forward
            curr1 = curr2; 
            curr2 = next2;
        }
        else {
            // move first list pointers forward
            curr1 = next1;
            next1 = next1->next;
        }
    }

    // If we exit because next1 reached NULL ? append all remaining curr2
    if (curr2 != NULL) {
        curr1->next = curr2;
    }

    return first;
}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    // Always start with the list with the smaller head
    if(first->data <= second->data){
        return solve(first, second);
    }
    else {
        return solve(second, first);
    }
}
