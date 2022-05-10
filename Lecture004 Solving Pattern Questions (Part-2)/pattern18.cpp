/*
Question : Triangle pattern 
given n= 4
Expected output 
_ _ _ *
_ _ * * 
_ * * * 
* * * * 
*/

#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int i = 1;
    while(i <= n){
        int space = n - i;
        int j = 1;
        while(j <= space && j <= n){
            cout << "  " ;
            j += 1;
        }
        int k = 1;
        while(k <= i){
            cout << "* " ;
            k += 1;
        }
        cout << endl;
        i += 1;
    }         
}
