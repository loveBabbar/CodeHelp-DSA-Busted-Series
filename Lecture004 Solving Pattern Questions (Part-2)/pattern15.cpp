/*
Question : Triangle pattern 
given n= 4
Expected output 
A 
B c
D E F  
G H I J 
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
        while(j <= i){
            char ch = 'A' + cnt - 1;
            cnt += 1;
            cout << ch << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }         
}
