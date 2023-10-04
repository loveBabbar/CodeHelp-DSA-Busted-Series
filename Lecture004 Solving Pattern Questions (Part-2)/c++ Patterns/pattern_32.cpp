#include<iostream>
using namespace std;

// E D C B A 
// E D C B A 
// E D C B A 
// E D C B A 
// E D C B A 

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=n) {
        int j = 1;
        while (j<=n) {
            cout<<char(n-j+'A')<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
