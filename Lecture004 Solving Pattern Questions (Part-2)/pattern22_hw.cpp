/*
Question : Triangle pattern 
given n= 4
Expected output 


      1 
    2 2 
  3 3 3 
4 4 4 4 

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
        int k = 1;
        while(k <= space){
            cout << "  " ;
            k += 1;
        }
        while(j <= (n - space) && j <= n){
            cout << i << " ";
            j += 1;
        }
        
        cout << endl;
        i += 1;
    }         
}
