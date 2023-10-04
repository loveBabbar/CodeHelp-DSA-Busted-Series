#include<iostream>
using namespace std;

// E E E E E 
// D D D D 
// C C C 
// B B 
// A

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=n) {
        int j = 1;
        while (j<=n-i+1) {
            cout<<char(n-i+'A')<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
