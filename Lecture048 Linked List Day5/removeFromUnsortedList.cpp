class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        if(head==NULL){
        return NULL;
    }
    Node* curr = head;
    map<int ,bool>  visited;
    visited[curr->data] = true;
    Node* prev = curr;
    curr = curr->next;
    while(curr!=NULL){   
        if(visited[curr->data]==true){
            prev->next = curr->next;
            free(curr);
        }else{
            visited[curr->data] = true;
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
     
    }
};
