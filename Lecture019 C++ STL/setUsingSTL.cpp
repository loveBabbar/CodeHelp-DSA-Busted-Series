#include <bits/stdc++.h>
#include <set>  //headerfile for implementing set as STL
using namespace std;

/*
set is a dataStructure which prints only unique elements present in it (i.e. if '5' is inserted 
into set 4-times then also, '5' will be printed only once).
Set is implemented using Binary-Search Tree(BST).
There are 2 types of set: set and unorderedSet.
Elements are printed in sorted order in set while in unorderedSet it prints in random order.
*/

int main()
{
    set <int> s;  //STL implementation of set

    s.insert(5);  //inserting elements into set
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    s.insert(8);
    s.insert(9);
    cout<<"printing elements from set: ";
    for(auto i:s) {  //printing elements present in set
        cout<<i<<" ";
    }
    cout<<endl;

    set <int> :: iterator it = s.begin();
    it++;  //now, iterator has moved to 2nd place in set (i.e. here '5' will be erased)
    s.erase(it);
    cout<<"elements present in set after erase is: ";
    for(auto i:s) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"present or not: "<<s.count(0)<<endl;  //tells whether the element specified is present or not (returns boolean value)
    
    set <int> :: iterator itr = s.find(6);
    /*if specified element is present in set then, find() returns the iterator of that element
    (i.e. the requested value or element)*/
    cout<<"value present at itr: "<<*itr<<endl;

    /*if want to print elements from a specified element 
    then, follow below code including find() statement (i.e. set<int>::iterator itr=s.find(6);)*/
    cout<<"printing elements from specified element 6: ";
    for(auto it=itr;it!=s.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
