/* BASIC OPERATIONS ON STACK USING LINKED LIST */
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class Stack
{
public:
  node *top;
  Stack(){
    top=NULL;
  }  
  void push(int d){
    node *temp=new node();
    temp->data=d;
    temp->next=top;
    top=temp;
  }
  node* pop(){
    if(top==NULL){
         cout<<"Stack is empty"<<endl;
    }
    else{
      cout<<"Popped element is:"<<top->data<<endl;
        top=top->next;
    }
    //return top;
  }
  node* peek(){
    if(top==NULL){
        cout<<"Stack is empty"<<endl;
    }
    else {
        cout<<"Element at top is:"<<top->data<<endl;
    }
    //return top;
  }
  
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.peek();
   s.pop();
   s.pop();
    return 0;
}
