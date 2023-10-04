#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// *
// * *
// * * *
// * * * *
// * * * * *

/* First approach: we are observing that row number from 1 to n (n is an integer value given by user) and in each row there is row number of columns.
// For Ex. first row has 1 column, 2nd has 2 columns, 3rd has 3 columns and so on.... */


int main() {

    int n, i=1;
    cin>>n;

    while (i<=n) {
        int j = 1;        
        while (j<=i) {
            cout<<"* "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}

// Alternate approach: Iterate both rows and columns till given number and print * only if row value is greater or equal to column value.

/* int main() {

    int n, i=1;
    cin>>n;

    while (i<=n) {
        int j = 1;        
        while (j<=n) {

            if(i>=j) {
                cout<<"* "; 
            }
            j++;
        }
        i++;
        cout<<endl;
    }
} */
