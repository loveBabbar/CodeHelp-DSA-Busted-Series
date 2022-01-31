//FAHRENHEIT TO CELCIUS

#include <iostream>
using namespace std;
int main()
{
    float f,c;
    cout<<"Enter value of temp in fahrenheit:- ";
    cin>>f;

    c=(5.0/9)*(f-32);

    cout<<"Conversion of "<<f<<" in celcius is:- "<<c<<endl;
    return 0;
}