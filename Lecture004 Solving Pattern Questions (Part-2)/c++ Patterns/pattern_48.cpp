#include<iostream>
using namespace std;

//         A 
//       A B A 
//     A B C B A 
//   A B C D C B A 
// A B C D E D C B A 

int main() {

    int n, i=1;
    cin>>n;
    
 
    while (i<=n) {
        int space = n-i;
        while(space) {
            cout<<"  ";
            space--;
        }

        int j = 1;
        while (j<=i) {  
            char ch = 'A'+j-1;
            cout<<ch<<" "; 
            j++;
        }

        int k = i-1;
        while (k>=1) {
            char ch = 'A'+k-1;
            cout<<ch<<" "; 
            k--;
        }

        i++;
        cout<<endl;
    }
}
