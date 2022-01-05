#include<iostream> 
using namespace std;

int fibbonacci(int n){

    // Base cases n==0 and n==1
    
    if(n==0){
            return 0;
        }
   
     if(n==1){
            return 1;
        }
     //recursive call    
   return fibbonacci(n-1)+fibbonacci(n-2);
 }

int main() {

    int n;

    cout<<"Enter n "<<endl;
    cin>>n;
    
    int ans =fibbonacci(n);
    
    System.out.println(ans)


    return 0;
}
