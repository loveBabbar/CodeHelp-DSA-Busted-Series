#include<iostream>
using namespace std;

int main()
{
    //data types:-  int, float, char, bool.

    int p = 7; // p is a variable. 
    unsigned short interger1 = 8;
    long integer2 = 8;
    short interger3 = 8; 

    float b = 8.5;
    double myfloat1 = 7.45;
    long double myfloat2 = 7.4654352;

    char c = 't'; //" " means string & ' ' means char. 
    //char = 'ab'  this is wrong as it is not a char , it is a string.
    
    bool bl = true;
    bool b2 = false;
    cout<<"boolean bl1 value is :- "<<bl<<endl;
    cout<<"boolean bl2 value is :- "<<b2<<endl;


    cout<<"hello ";
    cout<<"\nthis is int " <<p;
    cout<<"\nthis is float "<<b;
    cout<<"\nthis is char "<< c;

    //int - 2 to 4 bytes
    //float - 4 bytes - 6 decimal places
    //double - 8bytes - 15 decimal places.
    // long doble - 10bytes - 19 decimal places.
    //char - 1 byte

    cout<<"\nthe size taken by int is "<<sizeof(p);
    cout<<"\nthe size taken by char is "<<sizeof(c); 
    cout<<"\nthe size taken by boolean value is "<<sizeof(bool); 
    cout<<"\nthe size taken by float is "<< sizeof(float);
    cout<<"\nthe size taken by float is "<< sizeof(float);
    cout<<"\nthe size taken by unsigned int is "<< sizeof(unsigned int);
    cout<<"\nthe size taken by double is " << sizeof(double);
    cout<<"\nthe size taken by long double is "<< sizeof(long double);   

    return 0;
}