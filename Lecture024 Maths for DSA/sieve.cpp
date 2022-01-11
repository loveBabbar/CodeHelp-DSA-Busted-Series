#include<iostream>
#include<vector>
using namespace std;

//using Sieve
void sieve(bool prime[]) {

    //setting TRUE for every number
    for(int i=2;i<=1000000;i++){
        prime[i]=1;
    }

    for(int i = 2; i<=1000000; i++) {

        if(prime[i]){
            //iske saare multiple mark krde - non prime
            for(int j = 2*i; j<=1000000; j+=i){
                prime[j] = 0;   
            }
        }
    }
    prime[0] = prime[1] = 0;
}

int main() {

    bool prime[1000001];
    sieve(prime);

    int n;
    cin >> n;
    while(n!=-1) {
        if(prime[n]) {
            cout << "It is a Prime Number" << endl;
        }
        else{
            cout << " It is not a Prime Number" << endl;
        }
        cin >> n;
    }

    return 0;
}