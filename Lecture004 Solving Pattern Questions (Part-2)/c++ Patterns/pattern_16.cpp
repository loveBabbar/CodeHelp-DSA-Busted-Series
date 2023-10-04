#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// 1
// 2 3
// 4 5 6
// 7 8 9 10


/* Approach: we are observing that row number starts from 1 to n (n is an integer value given by user) and in each row there is i number of columns.
// For Ex. first row has 1 column, 2nd row has 2 columns, 3rd has 3 columns and so on.... and in each row we are printing value of count from 1.  */


int main() {

    int n, i=1, count=1;
    cin>>n;

    while (i<=n) {

        int j = 1;        
        while (j<=i) {
            cout<<count<<" "; 
            j++;
            count++;
        }
        i++;
        cout<<endl;
    }
}
