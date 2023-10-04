#include<iostream>
using namespace std;

// A B C D E 
// A B C D E 
// A B C D E 
// A B C D E 
// A B C D E 

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=n) {
        int j = 1;
        while (j<=n) {
            cout<<char('A'+j-1)<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
