#include<iostream>
using namespace std;

// E E E E E E E E E 
//   D D D D D D D 
//     C C C C C 
//       B B B 
//         A 

int main() {

    int n, i=1;
    cin>>n;
    
 
    while (i<=n) {
        int space = i-1;
        while(space) {
            cout<<"  ";
            space--;
        }

        int j = 2;
        while (j<=n-i+1) {  
            char ch = 'A'+n-i;
            cout<<ch<<" "; 
            j++;
        }

        int k = 1;
        while (k<=n-i+1) {
            char ch = 'A'+n-i;
            cout<<ch<<" "; 
            k++;
        }

        i++;
        cout<<endl;
    }
}
