#include<iostream>
using namespace std;

//         A 
//       A B C 
//     A B C D E 
//   A B C D E F G 
// A B C D E F G H I

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

        int k = 2;
        while (k<=i) {
            char ch = 'A'+i+k-2;
            cout<<ch<<" "; 
            k++;
        }

        i++;
        cout<<endl;
    }
}
