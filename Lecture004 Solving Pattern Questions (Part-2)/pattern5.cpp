// Triangle pattern 
/*
given n= 4
Expected output 
*
* *
* * *
* * * *
*/


#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the value of n: " ;
    cin >> n;

    int i = 1;
    while(i <= n){
        int j = 1;
        while (j <= i){
            cout <<  "*" << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }
    
}