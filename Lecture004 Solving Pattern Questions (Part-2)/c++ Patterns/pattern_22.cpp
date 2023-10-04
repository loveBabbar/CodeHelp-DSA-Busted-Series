#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// 10 9 8 7
// 6 5 4 
// 3 2 
// 1

/* Approach: we are observing that row number starts from 1 to n (n is an integer value given by user) and in each row there is n-i+1 number of columns.
// For Ex. first row has 4 column, 2nd row has 3 columns, 3rd has 2 columns and so on.... and in each row we are printing value of count which is starting from (n*(n+1))/2. */

int main() {

    int n, i=1;
    cin>>n;
    int count = n * (n+1) / 2;
 
    while (i<=n) {

        int j = 1;        
        while (j<=n-i+1) {
            cout<<count<<" "; 
            j++;
            count--;
        }
        i++;
        cout<<endl;
    }
}
