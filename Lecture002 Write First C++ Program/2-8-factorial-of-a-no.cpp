//FACTORIAL OF A NUMBER
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Write no you want to find factorial of :- ";
    cin>>n;
    
    int i=1;
    int fact=1;

    if (n<0)
    {
        cout<<"Fatorial of -ve no. can't be found."<<endl;        
    }
    else
    {
        for (i=1; i<=n; i++)
        {
            fact=fact*i;
        }
        cout<<"The factorial of "<<n<<" is "<<fact<<endl;
    }    

    return 0;
}