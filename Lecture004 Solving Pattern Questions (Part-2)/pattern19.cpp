/*
Question : Triangle pattern 
given n= 4
Expected output 


****
***
**
*

*/

#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int i = 1;
    while(i <= n){
        int star = n - i + 1;
        int j = 1;
        while(j <= star && j <= n){
            cout << "* " ;
            j += 1;
        }
        int k = 1;
        while(k <= i){
            cout << "  " ;
            k += 1;
        }
        cout << endl;
        i += 1;
    }         
}
