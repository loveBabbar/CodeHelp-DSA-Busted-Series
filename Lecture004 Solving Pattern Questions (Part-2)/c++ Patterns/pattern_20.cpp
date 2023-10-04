#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// 1 2 3 4
// 2 3 4
// 3 4 
// 4

/* Approach: we are observing that row number starts from 1 to n (n is an integer value given by user) and in each row there is n-i+1 number of columns.
// For Ex. first row has 4 column, 2nd row has 3 columns, 3rd has 2 columns and so on.... and in each row we are printing value of j. */

int main() {

    int n, i=1;
    cin>>n;

    while (i<=n) {

        int j = 1;        
        while (j<=n-i+1) {
            cout<<j<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
