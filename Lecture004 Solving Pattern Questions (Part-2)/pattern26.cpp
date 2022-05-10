#include <iostream>
using namespace std;

/*
Question : Triangle pattern 
given n= 5
Expected output 

1 2 3 4 5 5 4 3 2 1 
1 2 3 4 * * 4 3 2 1 
1 2 3 * * * * 3 2 1 
1 2 * * * * * * 2 1 
1 * * * * * * * * 1 
*/

int main(){
    int n;
    cout << "Enter the value of n:";
    cin >> n;

    int i = 1;
    while (i <= n){
        int star = i - 1;
        int j = 1;
        while(j <= (n - star)){
            cout << j << " ";
            j += 1;
        }
        int k = 1;
        while(k <= star){
            cout << "* *" << " ";
            k += 1;
        }
        j--;
        while(j){
            cout << j << " ";
            j--;
        }
        
        
        i += 1;
        cout << endl;
    }
}