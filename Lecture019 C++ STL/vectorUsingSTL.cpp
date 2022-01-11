#include <bits/stdc++.h>
#include <vector>  //headerfile for implementing vector as STL
using namespace std;

/*
vector is a dynamic array. It doubles its size, when it gets full and the 
user tries to add a new element into it.
*/

int main()
{
    vector <int> v;  //STL implementation of vector (initially, size of vector is 0)
    vector <int> a(5, 1);  //here, '5' is size of vector and '1' is initialized as all elements of the vector
    vector <int> b(a); //here, all the elements of 'a' vector are copied into 'b' vector

    cout<<"print vector b: ";
    for(int i:b) {
        cout<<i<<" ";  //printing the elements of the vector 'b'
    }
    cout<<endl;

    cout<<"capacity is: "<<v.capacity()<<endl;  //knowing the capacity of vector 'v'
    
    v.push_back(1);  //'1' is inserted as element into vector 'v'
    cout<<"capacity is: "<<v.capacity()<<endl;

    v.push_back(8);  //'8' is inserted as element into vector 'v'
    cout<<"capacity is: "<<v.capacity()<<endl;

    v.push_back(5);  //'5' is inserted as element into vector 'v'
    cout<<"capacity is: "<<v.capacity()<<endl;
    cout<<"size is: "<<v.size()<<endl;
    /*
    there, is a difference between size and capacity.
    Capacity means how much memory is allocated to the vector and
    Size means how many elements are present in the vector.
    */
    cout<<"elements of vector v are: ";
    for(int i:v) {
        cout<<i<<" ";  //printing the elements of the vector 'v'
    }
    cout<<endl;

    cout<<"element at 2nd index: "<<v.at(2)<<endl;  //for knowing element at specific index
    cout<<"first element of vector: "<<a.front()<<endl;  //for knowing first element of vector
    cout<<"last element of vector: "<<a.back()<<endl;  //for knowing last element of vector
    
    /*checking how pop in vector works*/
    cout<<"elements present before pop are: ";
    for(int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    v.pop_back(); //pop removes elements of vector from backwards 

    cout<<"elements present after pop are: ";
    for(int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    /*checking how clear in vector works*/
    cout<<"size before clear is: "<<v.size()<<endl;
    v.clear();  /*clear, clears the size of vector and not its capacity (i.e. it removes elements
    from vector and not the memory allocated to it)*/
    cout<<"size after clear is: "<<v.size()<<endl;

    return 0;
}
