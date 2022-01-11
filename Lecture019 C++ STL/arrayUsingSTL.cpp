#include <bits/stdc++.h>
#include <array>  //headerfile for implementing array as STL
using namespace std;

int main()
{
    array<int, 4> a = {1, 2, 3, 4};  //STL implementation of array
    
    cout<<"size of array: "<<a.size()<<endl;  //for calculating or knowing size of array

    int size = a.size();
    cout<<"elements of array are: ";
    for(int i=0;i<size;i++) {  //for accessing the elements of array
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"element at 2nd index: "<<a.at(2)<<endl;  //for knowing element at specific index
    cout<<"empty or not: "<<a.empty()<<endl;  //for knowing if array is empty or not (returns boolean value)
    cout<<"first element of array: "<<a.front()<<endl;  //for knowing first element of array
    cout<<"last element of array: "<<a.back()<<endl;  //for knowing last element of array

    return 0;
}
