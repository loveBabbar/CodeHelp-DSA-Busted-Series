#include <bits/stdc++.h>
#include <queue>  //headerfile for implementing priorityQueue as STL
using namespace std;

/*
priorityQueue is a type of queue which has biggest or largest element printing first.
PriorityQueue acts according to max-heap or min-heap.
While accessing the elements from max-heap, the greatest element among all is printed first.
Else while accessing the elements from min-heap, the smallest element among all is printed first.
*/

int main()
{
    /*priorityQueue using max-heap (i.e. printing largest element first)*/
    priority_queue <int> maxi;  //STL implementation of priorityQueue

    maxi.push(5);  //pushing or inserting elements into priorityQueue
    maxi.push(9);
    maxi.push(1);
    maxi.push(7);
    cout<<"size of priorityQueue is: "<<maxi.size()<<endl;  //for knowing size of priorityQueue
    int n = maxi.size();
    for(int i=0;i<n;i++) {  //printing elements present in priorityQueue
        cout<<maxi.top()<<" ";
        maxi.pop();  //removing or deleting elements from priorityQueue
    }
    cout<<endl;

    /*priorityQueue using min-heap (i.e. printing smallest element first)*/
    priority_queue <int, vector <int>, greater <int>> mini;  //STL implementation of priorityQueue

    mini.push(0);  //pushing or inserting elements in priorityQueue
    mini.push(8);
    mini.push(2);
    mini.push(6);
    mini.push(6);

    cout<<"size of priorityQueue is: "<<mini.size()<<endl;  //for knowing size of priorityQueue
    int m = mini.size();
    for(int i=0;i<m;i++) {
        cout<<mini.top()<<" ";
        mini.pop();  //removing or deleting elements from priorityQueue
    }
    cout<<endl;

    cout<<"is priorityQueue empty after popping all elements out: "<<mini.empty()<<endl;  //for knowing if queue is empty or not
    
    return 0;
}
