/****************************************************************
    Following is the class structure of the Node class:
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
*****************************************************************/
#include<unordered_map>
Node *removeDuplicates(Node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    unordered_map<int, bool> map;
    while(curr != NULL){
        if(map.find(curr->data) == map.end()){
            //Element not found in map
            map.emplace(curr->data, true);
            prev = curr;
            curr = curr->next;
        }
        else if(map[curr->data] == true){
            // Element found in map
            prev->next = curr->next;
            curr = curr->next;
        }
    }
    return head;
}
