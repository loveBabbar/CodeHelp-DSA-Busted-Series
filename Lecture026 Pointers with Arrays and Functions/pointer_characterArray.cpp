#include <iostream>

using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};
    char ch[4] = "abc";

    // cout works different in case of character array as compare to Integer array

    cout << arr << endl;
    cout << ch << endl;

    char *c = &ch[0];

    // Prints entire character array
    cout << c << endl;

    // This prints the values
    cout << *c << endl;

    // If there is no NUll values

    char temp = 'm';

    char *p = &temp;

    // Prints until it finds the Null character '\0'
    cout << p << endl;

    // Print the actual values
    cout << *p << endl;

    return 0;
}
