/*
Question : Triangle pattern 
given n= 4
Expected output 
1
2 3
3 4 5
4 5 6 7
*/

#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int i = 1;
    while(i <= n){
        int j = 0;
        while(j < i ){
            cout << j + i << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }
}
