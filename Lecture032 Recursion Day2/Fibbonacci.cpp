#include<iostream> 
using namespace std;

int fibo(int n){
    if (n == 0 || n == 1) return n;
    return fibo(n-1) + fibo(n-2);
}

int main() {

    int n;
    cout<<"Enter number : "<<endl;
    cin>>n;
    
    cout<<fibo(n)<<endl;


    return 0;
}
