#include<iostream>
using namespace std;

// A B C D E 
// A B C D 
// A B C 
// A B 
// A 

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=n) {
        int j = 1;
        while (j<=n-i+1) {
            cout<<char(j-1+'A')<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
