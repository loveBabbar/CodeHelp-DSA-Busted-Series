/********************************
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

********************************/

void splitCircularList(Node *head)
{
    if(head == NULL)
        return;
    Node *slow = head;
    Node *fast = head->next;
    while(fast != head && fast -> next != head){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
// Slow pointer points to the middle of the list
// Fast pointer points to the end of the list
    fast -> next = slow -> next;
    slow -> next = head;

}
