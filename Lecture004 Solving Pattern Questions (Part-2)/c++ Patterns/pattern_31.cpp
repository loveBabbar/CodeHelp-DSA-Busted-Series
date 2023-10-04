#include<iostream>
using namespace std;

// E E E E E 
// D D D D D 
// C C C C C 
// B B B B B 
// A A A A A 

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=n) {
        int j = 1;
        while (j<=n) {
            cout<<char(n-i+'A')<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
