#include <iostream>
using namespace std;

/*
Question : Triangle pattern 
given n= 5
Expected output 

        1         
      1 2 1       
    1 2 3 2 1     
  1 2 3 4 3 2 1   
1 2 3 4 5 4 3 2 1 
*/

int main(){
    int n;
    cout << "Enter the value of n:";
    cin >> n;

    int i = 1;
    while(i <= n){
        int fspace = n - i;
        int k = 1;
        while(k <= fspace){
            cout << "  ";
            k += 1;
        }
        int j = 1;
        while(j <= i){
            cout << j << " ";
            j += 1;
        }
        k--;
        j -= 2;
        while(j){
            cout << j << " ";
            j--;
        }
        while(k){
            cout << "  ";
            k--;
        }
        i += 1;
        cout << endl;
    }
}