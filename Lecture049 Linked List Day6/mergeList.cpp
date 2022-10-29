#include <bits/stdc++.h> 
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
Node<int>* MergeTwoSorted_LL(Node<int>* first,Node<int>* second){
    
    //If 1st Linked List contains only one element then it next will be pointed to 2nd Linked List
    if(first->next==NULL){
        first->next=second;
        return first;
    }


    Node<int>* curr1= first;
    Node<int>* next1=curr1->next;
    Node<int>* curr2=second;
    Node<int>* next2=curr2->next;
    

     while(next1!=NULL && curr2!=NULL){

       if((curr2->data<=next1->data) && (next1->data>=curr2->data)){
        
        // Inserting the node in the Linked List
        curr1->next=curr2;
        next2=curr2->next;
        curr2->next=next1;
           
        // updating pointers
        curr1=curr2;
        curr2=next2; 
       
       }
       else{
           
           //If Element can't be inserted we will move the pointer to next nodes   
            curr1=next1;
            next1=next1->next;
           
         // If next for 1st LL node reach NULL
         if (next1==NULL){
            curr1->next=curr2;
            return first;
            }
        }
    }

     return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    //Checking if any of the Linked list is NULL
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    
    
    if(first->data<=second->data){
            return MergeTwoSorted_LL(first , second);
        }
    else{
           return MergeTwoSorted_LL(second , first);
        }
}
