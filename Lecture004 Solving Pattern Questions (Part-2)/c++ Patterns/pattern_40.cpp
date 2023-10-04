#include<iostream>
using namespace std;

//         A 
//       A B 
//     A B C 
//   A B C D 
// A B C D E 

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
            cout<<char(j-1+'A')<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
