#include <iostream>
using namespace std;

/*
Given n= 3
expected output 
1 2 3 
4 5 6 
7 8 9
*/

int main(){
    int n;
    cout << "Enter the value of n:";
    cin >> n;

    int i = 1, cnt = 1;
    while( i <= n){
        int j = 0;
        while (j < n){
            cout << cnt << " ";
            // cout << " ";
            cnt += 1;
            j += 1;
        }
        i += 1;
        cout << endl;
    }


}