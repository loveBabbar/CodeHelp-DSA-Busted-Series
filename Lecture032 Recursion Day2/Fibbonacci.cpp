#include<iostream> 
using namespace std;
int fib(int n){
    if(n==0||n==1)
        return n;
    else
        return fib(n-1) + fib(n-2);   // recursive call to find the nth fibonacci  number  --> O(n^2)
}


int main() {

    int n; 
    cin>>n;  // stdin the nth term to find the fibonacci number
    cout<<"The "<<n<<" term of fibonacci is "<<fib(n);


    return 0;
}
