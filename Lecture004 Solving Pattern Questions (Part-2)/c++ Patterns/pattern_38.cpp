#include<iostream>
using namespace std;

// E D C B A 
// E D C B 
// E D C 
// E D 
// E 

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=n) {
        int j = 1;
        while (j<=n-i+1) {
            cout<<char(n-j+'A')<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
