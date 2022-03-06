#include <bits/stdc++.h>
#include <deque>  //headerfile for implementing deque as STL
using namespace std;

int main()
{
    deque <int> d;  //STL implementation of deque

    /*inserting elements into deque*/
    d.push_back(9);  //inserts element into deque from back
    d.push_front(4);  //inserts element into deque from front
    d.push_front(7);
    d.push_back(3);
    d.push_front(2);
    cout<<"elements present after pushing into deque are: ";
    for(int i:d) {
        cout<<i<<" ";
    }
    cout<<endl;

    /*removing elements from deque*/
    d.pop_front();
    d.pop_back();
    cout<<"elements present after poping from deque are: ";
    for(int i:d) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"first element of deque: "<<d.front()<<endl;  //for knowing first element of deque
    cout<<"last element of deque: "<<d.back()<<endl;  //for knowing last element of deque

    cout<<"empty or not: "<<d.empty()<<endl;  //for knowing if deque is empty or not (returns boolean value)
    
    /*checking how erase works in deque*/
    cout<<"size of deque before erase: "<<d.size()<<endl;
    d.erase(d.begin());  //erases element from front (i.e. first element)
    d.erase(d.end());  //erases element from back (i.e. last element)
    /*erase, erases the size of vector and not its capacity (i.e. it removes elements
    from vector and not the memory allocated to it)*/
    cout<<"size of deque after erase: "<<d.size()<<endl;
    cout<<"elements present after erase are: ";
    for(int i:d) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
