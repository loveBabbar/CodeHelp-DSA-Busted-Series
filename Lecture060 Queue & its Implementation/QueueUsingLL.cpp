#include <iostream>
using namespace std;
/*
Time Complexity: Time complexity of both operations enqueue() and dequeue() is O(1)
 as we only change few pointers in both operations. There is no loop in any of the operations.
Auxiliary Space: Space complexity of both operations enqueue() and dequeue() is O(1) 
as constant extra space is required. */
class Queue{

    int data;
    Queue *next;
    

    public:
    Queue(int data){
        this -> data = data;
        this -> next = NULL;
    }

    bool enqueue(Queue* &front, Queue* &rear, int val){
        //check if first element
        Queue* newNode = new Queue(val);
        if(front == NULL){
            front = newNode;
            rear = newNode;
            return true;
        }else{
            //assuming element is present
            rear -> next = newNode;
            rear = newNode;
            return true;
        }       

    }

    int dequeue(Queue* &front, Queue* &rear){
        //check if no element is present
        if(front == NULL){
            return -1;
        }else{
          //if present then move front ahead and return
            int res = front->data;
            front = front -> next;
            return res;
        }
    }

    bool isEmpty(Queue* &front){
      //if front is null meaning queue is empty
        if(front == NULL) return true;

        else return false;
    }

    int frontofQ(Queue* &front){
        if(front!=NULL)
          //if front is not null so we return front element
         return front->data;
        else
           return -1;
    }
};

int main(){
    Queue* front = NULL;
    Queue* rear = NULL;
    Queue q(-1);

    q.enqueue(front,rear,15);
    q.enqueue(front,rear,20);
    q.enqueue(front,rear,25);

    cout << "Dequeue element from Queue is "<< q.dequeue(front,rear) << endl;

    cout << "Front of the queue is "<< q.frontofQ(front) << endl;

    cout << q.dequeue(front,rear) << '\n';
    if( q.isEmpty(front)) cout << "Queue is empty " << endl;
    else cout << "Not empty" << endl;
    cout << q.dequeue(front,rear) << '\n';


    if( q.isEmpty(front)) cout << "Queue is empty " << endl;
    else cout << "Not empty" << endl;




    return 0;



}
