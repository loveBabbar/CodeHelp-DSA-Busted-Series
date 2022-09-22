/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/
//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if(head==NULL || head->next==NULL)
        return;
    Node* slow=head;
    Node* fast=head;
    
    while(fast->next!=head && fast->next->next!=head){
        fast=fast->next->next;
        slow=slow->next;
    }
    *head1_ref=head;
    *head2_ref=slow->next;
    slow->next=head;
    Node* temp=*head2_ref;
    while(temp->next!=head)
        temp=temp->next;
    temp->next=*head2_ref;
}




