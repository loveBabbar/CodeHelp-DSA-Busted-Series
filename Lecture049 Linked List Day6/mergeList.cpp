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
Node<int>* solve(Node<int> *first, Node<int> *second)
{
    if(first->next==NULL)
    {
        first->next=second;
        return first;
    }
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2->next;
    while(next1!=NULL && curr2!=NULL)
    // window should contain two numbers
    {
           if((curr1->data<=curr2->data) && (next1->data>=curr2->data))
           {
               //adding the node
               curr1->next=curr2;
               next2=curr2->next;
               curr2->next=next1;

               //updating the next node for further addition
               curr1=curr2;
               curr2 = next2;

           }
           else
           {
               //we will slide the window
               curr1=next1;
               next1= next1->next;

             // agar window end tak pahuch gayi hai or dusri linked list baaki hai toh
             // hum curr1 ke node ko curr2 se jod denge
               if(next1==NULL)
               {
                   curr1->next=curr2;
                    return first;
               }
           }
          

           


       
    }

 return first;
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second) {
  if (first == NULL)
  {
      return second;
  }
  if(second ==NULL)
  {
      return first;
  }

  if(first->data<=second->data)
  {
      return solve(first,second);
  }
  else{
      return solve(second,first);
  }
   
  }

