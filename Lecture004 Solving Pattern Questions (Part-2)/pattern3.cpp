#include <iostream>
using namespace std;

/*
given n = 4
expected pattern  
1 2 3 4 
1 2 3 4 
1 2 3 4 
1 2 3 4 
*/

int main(){
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;

    int i = 1;

    while (i <= n){
        int j = 1;
        while (j <= n){
            cout << j << " ";
            j += 1;
        }
        i += 1;
        cout << endl;
    }

}