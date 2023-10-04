#include<iostream>
using namespace std;

//         A 
//       C B A 
//     E D C B A 
//   G F E D C B A 
// I H G F E D C B A 

int main() {

    int n, i=1;
    cin>>n;
    
 
    while (i<=n) {
        int space = n-i;
        while(space) {
            cout<<"  ";
            space--;
        }

        int j = 1,c=(2*i)-1;
        while (j<=i) {  
            char ch = 'A'+c-1;
            cout<<ch<<" "; 
            j++;
            c-=1;
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
