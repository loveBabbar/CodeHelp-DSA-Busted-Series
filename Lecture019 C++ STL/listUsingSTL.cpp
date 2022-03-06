#include <bits/stdc++.h>
#include <list>  //headerfile for implementing list as STL
using namespace std;

/*
particular element in list cannot be accessed directly like other data structures such as
array, vector, etc. For accessing a particular element in list, we need to traverse till
that index from first or from last (a major drawback of list)
*/

int main()
{
    list <int> l;  //STL implementation of list
    list <int> a(4, 100);  //here, '4' is size of list and '100' is initialized as all elements of the list
    cout<<"elements present in list 'a' are: ";
    for(int i:a) {
        cout<<i<<" ";
    }
    cout<<endl;

    l.push_back(13);  //inserts element into list from back
    l.push_front(8);  //inserts element into list from front
    l.push_front(5);
    cout<<"elements present in list 'l' are: ";
    for(int i:l) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"size of list: "<<l.size()<<endl;  //for knowing size of list

    /*checking how erase works in list*/
    cout<<"size of list before erase: "<<l.size()<<endl;
    l.erase(l.begin());  //erases element from front (i.e. first element)
    /*erase, erases the size of list and not its capacity (i.e. it removes elements
    from list and not the memory allocated to it)*/
    cout<<"size of list after erase: "<<l.size()<<endl;
    cout<<"elements present after erase are: ";
    for(int i:l) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
