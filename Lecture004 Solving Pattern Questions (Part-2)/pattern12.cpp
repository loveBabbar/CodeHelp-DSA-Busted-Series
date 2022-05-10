/*
Question : Triangle pattern 
given n= 4
Expected output 
A B C D
E F G H
I J K L 
M N O P
*/

#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int i = 1;
    int cnt = 1;
    while(i <= n){
        int j = 1;
        while(j <= n){
            char ch = 'A' + cnt  - 1;
            cnt += 1;
            cout << ch << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }         
}
