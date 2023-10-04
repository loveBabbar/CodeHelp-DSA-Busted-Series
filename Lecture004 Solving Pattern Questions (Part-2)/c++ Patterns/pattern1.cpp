#include<iostream>
using namespace std;

// Printing patterns using conditionals and if loops

// * * * *       
// * * * *     
// * * * *   
// * * * * 

int main() {

    int n, i=1;
    cin>>n;

    while (i<=n) {
        int j = 1;        
        while (j<=n) {
            cout<<"* "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
