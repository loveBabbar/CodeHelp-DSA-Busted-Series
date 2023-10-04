#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

//       4 
//     3 4 
//   2 3 4 
// 1 2 3 4 

/* Approach: we are observing that row number starts from 1 to n (n is an integer value given by user) and in each row there is i number of columns and n-i spaces.
// For Ex. first row has 1 column and 3 spaces, 2nd row has 2 columns and 2 spaces, 3rd has 2 columns and so on.... and in each row we are printing value of n-i+j. */

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=n) {

        int space = n-i;        
        while (space) {
            cout<<"  "; 
            space--;
        }

        int j = 1;        
        while (j<=i) {
            cout<<n-i+j<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
