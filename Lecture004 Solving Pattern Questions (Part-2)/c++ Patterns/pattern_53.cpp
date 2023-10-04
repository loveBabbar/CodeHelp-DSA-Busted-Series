#include<iostream>
using namespace std;

// D 
// C D 
// B C D 
// A B C D 
// B C D 
// C D 
// D 

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=(2*n)-1) {

        if(i<=n) {
            int j = 1;
            while (j<=i) {
                char ch = 'A'+n-i+j-1; 
                cout<<ch<<" "; 
                j++;  
            }
        }
        if(i>n) {
            int k=2;
            while (k<=(2*n)-i+1) {
                char ch = 'A'+i+k-n-2; 
                cout<<ch<<" "; 
                k++;  
            }
        }
        i++;
        cout<<endl;
    }
}
