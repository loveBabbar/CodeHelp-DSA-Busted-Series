#include<iostream>
using namespace std;

// D 
// D C 
// D C B 
// D C B A 
// D C B 
// D C 
// D 

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=(2*n)-1) {
        if(i<=n) {
            int j = 1;
            while (j<=i) {
                char ch = 'A'+n-j; 
                cout<<ch<<" "; 
                j++;  
            }
        }
        if(i>n) {
            int k = 2;
            while (k<=(2*n)-i+1) {
                char ch = 'A'+n-k+1; 
                cout<<ch<<" "; 
                k++;  
            }
        }
        i++;
        cout<<endl;
    }
}
