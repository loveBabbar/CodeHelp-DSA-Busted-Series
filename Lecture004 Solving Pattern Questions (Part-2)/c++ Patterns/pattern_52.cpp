#include<iostream>
using namespace std;

//         A 
//       B A B 
//     C B A B C 
//   D C B A B C D 
// E D C B A B C D E 

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
            char ch = 'A'+i-j; 
            cout<<ch<<" "; 
            j++;  
        }

        int k=2;
        while (k<=i) {
            char ch = 'A'+k-1; 
            cout<<ch<<" "; 
            k++;  
        }
        i++;
        cout<<endl;
    }
}
