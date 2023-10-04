#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// 4
// 3 3 
// 2 2 2
// 1 1 1 1


/* Approach: we are observing that row number starts from 1 to n (n is an integer value given by user) and in each row there is i number of columns.
// For Ex. first row has 1 column, 2nd row has 2 columns, 3rd has 3 columns and so on.... and in each row we are printing value of n-i+1 number itself.  */


int main() {

    int n, i=1;
    cin>>n;

    while (i<=n) {

        int j = 1;        
        while (j<=i) {
            cout<<n-i+1<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
