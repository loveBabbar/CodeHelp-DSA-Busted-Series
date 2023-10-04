#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// 1 2 3 4
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4

int main() {

    int n, i=1;
    cin>>n;

    while (i<=n) {
        int j = 1;        
        while (j<=n) {
            cout<<j<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
