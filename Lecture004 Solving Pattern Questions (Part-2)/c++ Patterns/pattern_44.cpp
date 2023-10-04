#include<iostream>
using namespace std;

//         A 
//       B B B 
//     C C C C C 
//   D D D D D D D 
// E E E E E E E E E 

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
            char ch = 'A'+(2*i)-2;
            cout<<ch<<" "; 
            j++;
        }

        int k = 2;
        while (k<=i) {
            char ch = 'A'+(2*i)-2;
            cout<<ch<<" "; 
            k++;
        }

        i++;
        cout<<endl;
    }
}
