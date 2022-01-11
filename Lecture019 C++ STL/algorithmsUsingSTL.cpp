#include <bits/stdc++.h>
#include <algorithm>  //headerfile for implementing algorithms as STL
#include <vector>  //headerfile for implementing vector as STL
using namespace std;

int main()
{
    vector <int> v;
    v.push_back(3);
    v.push_back(9);
    v.push_back(16);
    v.push_back(22);
    v.push_back(36);
    cout<<"elements of vector are: ";
    for(int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    /*binary search*/
    cout<<"finding specified element: "<<binary_search(v.begin(), v.end(), 22)<<endl;  //returns boolean value
    
    /*lower and upper bound*/
    cout<<"lower bound is: "<<lower_bound(v.begin(), v.end(), 3) - v.begin()<<endl;
    cout<<"upper bound is: "<<upper_bound(v.begin(), v.end(), 36) - v.begin()<<endl;

    /*rotating*/
    rotate(v.begin(), v.begin() + 1, v.end());
    cout<<"elements after rotating 1 element: ";
    for(int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    /*sorting*/
    //sort() is implemented using introSort = (heap + insertion + quick) sort
    sort(v.begin(), v.end());
    cout<<"elements after sorting: ";
    for(int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;
    
    int a = 5, b = 10;
    /*minimum and maximum*/
    cout<<"max among a and b is: "<<max(a, b)<<endl;
    cout<<"min among a and b is: "<<min(a, b)<<endl;

    /*swap*/
    swap(a, b);
    cout<<"swapping values of a and b: "<<a<<" "<<b<<endl;

    string s = "abcd";
    /*reversing*/
    reverse(s.begin(), s.end());
    cout<<"reversed string is: "<<s<<endl;
    return 0;
}
