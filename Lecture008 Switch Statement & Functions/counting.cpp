#include<iostream>
using namespace std;

//Function Signature
void printCounting(int num) {

//    cout << n << endl;
    //Function Body 
    for(int i=1; i<=num; i++) {
        cout<< i << " ";
    }
    cout<<endl;
}

int main() {

    int n;
    cin >> n;

    //function Call
    printCounting(n);


    return 0;
}