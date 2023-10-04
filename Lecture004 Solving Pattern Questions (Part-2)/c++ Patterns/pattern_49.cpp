#include<iostream>
using namespace std;

// G G G G G G G 
//   E E E E E 
//     C C C 
//       A 

int main() {

    int n, i=1;
    cin>>n;
    int c=(2*n)-i;
 
    while (i<=n) {
        int space = i-1;
        while(space) {
            cout<<"  ";
            space--;
        }

        int j = 1;
        while (j<=n-i+1) {
            char ch = 'A'+c-1; 
            cout<<ch<<" "; 
            j++;  
        }
        
        int k = 2;
        while (k<=n-i+1) {
            char ch = 'A'+c-1;
            cout<<ch<<" "; 
            k++;
        }

        i++;
        c-=2;
        cout<<endl;
    }
}
