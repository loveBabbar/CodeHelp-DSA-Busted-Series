/*
Question : Triangle pattern 
given n= 4
Expected output 
D
C D
B C D 
A B C D 
*/

#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int i = 1;
    while(i <= n){
        int j = 1;
        char ch = 'A' + n - i;
        while(j <= i){
            cout << ch << " ";
            ch = ch + 1;
            j += 1;
        }
        cout << endl;
        i += 1;
    }         
}
