#include<iostream>
using namespace std;

// A B C D E F G 
//   A B C D E 
//     A B C 
//       A 

int main() {

    int n, i=1;
    cin>>n;
 
    while (i<=n) {
        int space = i-1;
        while(space) {
            cout<<"  ";
            space--;
        }

        int j = 1;
        while (j<n-i+1) {
            char ch = 'A'+j-1; 
            cout<<ch<<" "; 
            j++;  
        }
        
        int k = 1;
        char ch = 'A'+n-i;
        while (k<=n-i+1) {
            cout<<ch<<" "; 
            k++;
            ch++;
        }

        i++;
        cout<<endl;
    }
}
