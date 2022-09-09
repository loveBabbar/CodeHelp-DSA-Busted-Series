/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    /*Only solve one case of duplicate head and recursion will take care of remaining list*/
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Base Case
        if(head == NULL || head->next ==NULL){
            //0 OR 1 node in list 
            return head;
        }
        // Step 1. While head itself is duplicate delete head.
        while(head != NULL && head->next != NULL && head->next->val == head->val){
             while(head->next != NULL && head->next->val == head->val){
                head = head->next;
            }
            head = head->next;
        }
        //After changing head if head is NULL or there is only single node in list return head
        if(head == NULL || head->next ==NULL){
            return head;
        }
        
        // Step 2.
        // (i) Now we have got a unique head, so we don't have to worry about it anymore.
        // (ii) We will ask recursion to delete duplicates from the next node and return its unique head.
        // (iii) When we'll get unique head from recursion, we'll attach it to our unique head.
        head->next = deleteDuplicates(head ->next);
        
        // Step 3. We will return head once we have received an answer.
        return head;
    }
};
