#include<iostream>
using namespace std;

int main() {

    int n ;
    cout<<" enter the value of n" <<endl;
    cin >> n;

    int sum = 0;
    
    for(int i=1; i<=n; i++ ) {
        //sum = sum + i;
        sum += i;
    }

    cout<< sum <<endl;
    return 0;
}