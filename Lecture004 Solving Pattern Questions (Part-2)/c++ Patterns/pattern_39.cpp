#include<iostream>
using namespace std;

//         A 
//       B B 
//     C C C 
//   D D D D 
// E E E E E 

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
            cout<<char(i-1+'A')<<" "; 
            j++;
        }
        i++;
        cout<<endl;
    }
}
