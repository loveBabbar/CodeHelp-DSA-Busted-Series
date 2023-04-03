
#include <iostream>

using namespace std;

int fibo(int num){
    
    //base case
    if(num == 1 || num == 0)
    return num;
    
    //recursive call
    int ans = fibo(num-1) + fibo(num-2);
    
    return ans;
}

int main()
{
    int num;
    
    cin >> num;
    
    int n = fibo(num);
    
    cout<< n << endl; 
    return 0;
    
}
