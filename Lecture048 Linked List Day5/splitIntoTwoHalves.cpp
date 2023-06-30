// Solution to "Split a Circular Linked List into two halves" question on gfg.
// Question link -> https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node* slow = head;
    Node* fast = head;
    
    do{
        fast = fast->next;
        if(fast->next == head){
            break;
        }
        fast = fast->next;
        slow = slow->next;
        
    }while(fast->next != head);
    
    //The above code is written after doing pen-paper dry run with 6 and 5 nodes.
    //Now, slow points to end of 1st half, fast points to end of 2nd half.
    
    Node* firstHalf = head;
    Node* secondHalf = slow->next;
    slow->next = firstHalf;
    fast->next = secondHalf;
    
    *head1_ref = firstHalf;
    *head2_ref = secondHalf;
    
    return;
}
