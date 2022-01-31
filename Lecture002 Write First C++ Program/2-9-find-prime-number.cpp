//TO FIND A NUMBER IS A PRIME OR NOT
#include<iostream>
using namespace std;
int main()
{
    int n ;
    cout<<"enter a number:- ";
    cin>>n;

    int i = 2;
    if (i<n)
    {
        if(n%i==0)
        {
            cout<<n<<" is a non-prime number.\nIt is a composite number"<<endl;
        }
        else
        {
            i=i+1;
            cout<<n<<" is a prime number."<<endl;
        }        
    }
    else
    {
        cout<<"It is smaller than than 1st prime number."<<endl;
    }    
    return 0;
}