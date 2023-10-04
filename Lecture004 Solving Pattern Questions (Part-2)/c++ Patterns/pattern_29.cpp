#include<iostream>
using namespace std;

// A A A A A
// B B B B B
// C C C C C
// D D D D D
// E E E E E

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=n) {
        int j = 1;
        while (j<=n) {
            cout<<char('A'+i-1)<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
