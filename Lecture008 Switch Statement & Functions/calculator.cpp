#include<iostream>
using namespace std;
int main()
{
    int ch;
    cout<<"Enter 1 for addition 2 for substraction 3 for multipliaction 4 for divison : ";
    cin>>ch;
    int x,y;
    cout <<"Enter the values of x : ";
    cin>>x;
    cout <<"Enter the values of y : ";
    cin>>y;
    int a=x+y;
    int s=x-y;
    int m=x*y;
    int d=x/y;
    int r=x%y;
    switch(ch)
    {
        case 1: cout<<"Addition : "<<a;
                break;
        case 2: cout<<"Substraction : "<<s;
                break; 
        case 3: cout<<"Multipication : "<<m;
                break;
        case 4: cout<< "Divison : "<<d;
                break;
        case 5: cout<<"Modulo : "<<r;
                break; 
       default: cout<<"invalid input";
                break;                  
    }
    return 0;
}
