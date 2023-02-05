#include<iostream>
using namespace std;

class node
{   public:

    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~node(){
        int value= this->data; 
        delete next;
        if(this->next!=NULL)
        {
            this->next= NULL;
        }
    }

};

void insertathead(node* &head, int data)
{
   node* temp= new node(data);
   temp->next= head ;
   head= temp;


}


void printcircular(node* &head)
{
    node* temp= head;

    do
    {
        cout<<temp->data<<" ";
        temp= temp->next;

    }while(temp!=head);
    cout<<endl;
}


void splitll(node* &head)
{
    node* temp= head;
    node* slow= head;
    node* fast= head;

   do
    {
        fast= fast->next;
        if(fast->next!= head)
       { fast= fast->next;
        slow= slow->next;}

    } while(fast->next!= head && fast!= head);
    node* head2= slow->next;
    fast->next= head2;
    slow->next=temp;
     
     printcircular(head);
     printcircular(head2);

}

main()
{
    node* node1= new node(7);
    node* head= node1;
    node* temp= head;
    insertathead(head, 2);
    insertathead(head, 5);
    insertathead(head, 2);
    insertathead(head, 1);
    insertathead(head, 4);
    insertathead(head, 8);
    insertathead(head, 3);
    insertathead(head, 1);
    temp->next= head;
    printcircular(head);
    splitll(head);
}
