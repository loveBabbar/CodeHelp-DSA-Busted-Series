#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// * * * * *
// * * * *
// * * *
// * *
// * 

/* Approach: we are observing that row number from 1 to n (n is an integer value given by user) and in each row there is n-row+i number of columns.
For Ex. first row has 4-1+1=4 column, 2nd has 4-2+1=3 columns, 3rd has 2 columns and so on.... */

int main() {

    int n, i=1;
    cin>>n;

    while (i<=n) {
        int j = 1;        
        while (j<=n-i+1) {
            cout<<"* "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
