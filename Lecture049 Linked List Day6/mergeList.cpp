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

// All testcase passed in Leetcode

Node<int>* solve(Node<int>* first,Node<int>* second){
        Node<int>* curr1=first;
        Node<int>* next1=first->next;

        Node<int>* curr2=second;
        Node<int>* next2=curr2->next;
        while(next1 != NULL && curr2 != NULL){
            if(curr2->val >= curr1->val  &&  curr2->val <= next1->val ){
                curr1->next=curr2;
                next2=curr2->next;
                curr2->next=next1;

                curr1=curr2;
                curr2=next2;
            }
            else{

                if(curr1->next == NULL){
                    curr1->next= curr2;
                    return first;
                }
                curr1=next1;
                
                next1=next1->next;
            }
              
        }
        //for that one base case
        if(curr1->next == NULL){
            curr1->next=curr2;
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
