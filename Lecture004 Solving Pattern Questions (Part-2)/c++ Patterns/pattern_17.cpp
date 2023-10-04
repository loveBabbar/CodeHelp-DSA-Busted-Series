#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// 1
// 2 3
// 3 4 5
// 4 5 6 7


/* Approach: we are observing that row number starts from 1 to n (n is an integer value given by user) and in each row there is i number of columns.
// For Ex. first row has 1 column, 2nd row has 2 columns, 3rd has 3 columns and so on.... and in each row we are printing value of i+j-1.  */


int main() {

    int n, i=1;
    cin>>n;

    while (i<=n) {

        int j = 1;        
        while (j<=i) {
            cout<<i+j-1<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
