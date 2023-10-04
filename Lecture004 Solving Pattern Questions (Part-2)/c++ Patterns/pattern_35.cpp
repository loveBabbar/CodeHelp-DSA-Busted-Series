#include<iostream>
using namespace std;

// A A A A A 
// B B B B 
// C C C 
// D D 
// E 

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=n) {
        int j = 1;
        while (j<=n-i+1) {
            cout<<char(i-1+'A')<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
