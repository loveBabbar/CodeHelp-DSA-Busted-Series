#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// 4 3 2 1
// 4 3 2 1
// 4 3 2 1
// 4 3 2 1

int main() {

    int n, i=1;
    cin>>n;

    while (i<=n) {
        int j = 1;        
        while (j<=n) {
            cout<<n-j+1<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
