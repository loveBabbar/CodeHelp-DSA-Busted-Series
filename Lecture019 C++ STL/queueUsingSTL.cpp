#include <bits/stdc++.h>
#include <queue>  //headerfile for implementing queue as STL
using namespace std;

/*
queue can be understood by example of: boys standing in a row, one behind another.
i.e. it follows rule of: first-in first-out(FIFO) and last-in last-out(LILO)
*/

int main()
{
    queue <string> q;  //STL implementation of queue

    q.push("Hallo");  //pushing elements into the queue
    q.push("Bonjour");
    q.push("Ciao");
    cout<<"first element in the queue is: "<<q.front()<<endl;  //for knowing first element of the queue
    cout<<"last element in the queue is: "<<q.back()<<endl;  //for knowing last element of the queue

    /*checking how pop works in queue*/
    cout<<"size of queue: "<<q.size()<<endl;  //for knowing size of the queue
    q.pop();  //removing elements from the queue
    cout<<"size of queue after pop: "<<q.size()<<endl;
    cout<<"first element in queue after pop is: "<<q.front()<<endl;

    cout<<"empty or not: "<<q.empty()<<endl;  //for knowing if queue is empty or not

    return 0;
}
