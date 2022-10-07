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
    if(head == NULL || head->next == NULL) return;
    Node * fast = head->next;
    Node * slow = head;
    
    while(fast->next!=head){
        fast = fast->next;
        if(fast->next == head){
            fast->next = slow->next->next;
            slow->next->next = head;
            return;
        }
        fast = fast->next;
        slow = slow->next;
    }   
    
    fast->next = slow->next;
    slow->next = head;
}
