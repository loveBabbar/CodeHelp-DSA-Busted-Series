#include<iostream>
using namespace std;
int main()
{
    cout<<"\n\n*******RULES FOR CRAETING VARIABLES********\n";
    int khushiName; //variablle declaration
    khushiName = 5; //variable initialization
    char ch = 'k'; // variable declaration and initialization
    const int i = 9;
    // i = 10; it will show error as 'i' is constant.
    
    cout<<khushiName<<endl;
    cout<< ch <<endl;
    cout << i <<endl;

    //STORING -VE IN UNSIGNED INT AND SEING ITS RESULT
    int q = 112;
    cout<<q<<endl;
    unsigned int p = -112;
    cout<<p<<endl;

    return 0;
}