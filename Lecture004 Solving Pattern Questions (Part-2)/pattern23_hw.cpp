/*
Question : Triangle pattern 
given n= 4
Expected output 

1 2 3 4 5 
  1 2 3 4 
    1 2 3 
      1 2 
        1 
*/

#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int i = 1;
    while(i <= n){
        int space = i - 1;
        int j = 1;
        int k = 1;
        while(k <= space){
            cout << "  " ;
            k += 1;
        }
        while(j <= (n - i + 1)){
            cout << j << " ";
            j += 1;
        }    
        cout << endl;
        i += 1;
    }         
}
