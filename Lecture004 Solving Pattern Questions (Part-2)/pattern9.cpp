/*
Question : Triangle pattern 
given n= 4
Expected output 
1
2 1
3 2 1
4 3 2 1
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
        while(j <= i){
            cout << i - j + 1 << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }        
}
