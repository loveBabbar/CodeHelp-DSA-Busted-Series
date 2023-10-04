#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// 9 8 7 
// 6 5 4 
// 3 2 1 

int main() {

    int n, i=1;
    cin>>n;
    int count=n*n;

    while (i<=n) {
        int j = 1;        
        while (j<=n) {
            cout<<count<<" "; 
            j++;
            count--;
        }
        i++;
        cout<<endl;
    }
}
