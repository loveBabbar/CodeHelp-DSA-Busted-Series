#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// * * * * *
//   * * * *
//     * * *
//       * *
//         *


/* Approach: we are observing that row number from 1 to n (n is an integer value given by user) and in each row there is n-i+1 number of * and i-1 spaces.
// For Ex. first row has 1 * and 4 spaces, 2nd row has 2 * and 3 spaces, 3rd has 3 * and 2 spaces and so on.... */


int main() {

    int n, i=1;
    cin>>n;

    while (i<=n) {

        int space = i-1;
        while(space) {
            cout<<"  ";
            space--;
        }

        int j = 1;        
        while (j<=n-i+1) {
            cout<<"* "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
