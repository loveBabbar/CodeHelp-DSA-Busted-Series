/*
Question : Triangle pattern 
given n= 4
Expected output 
A B C D
B C D E
C D E F
D E F G
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
        while(j <= n){
            char ch = 'A' + i + j  - 2;
            cout << ch << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }         
}
