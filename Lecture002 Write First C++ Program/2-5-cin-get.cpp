// TO READ WHITE SPACES (SPACEBAR, ENTER & TAB)
// WE USE cin.get()

#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"enter input :- "; // IN INPUT GIVE SPACE or TAB or ENTER KEY.
    a = cin.get();
    cout<<"OUTPUT IS :- "<<a<<endl;;
    // we will get output as ASCII values of white spaces. 
    return 0;
}