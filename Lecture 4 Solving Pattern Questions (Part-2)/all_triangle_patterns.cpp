#include <iostream>

using namespace std;

void pattern1();
void pattern2();
void pattern3();
void pattern4();

int main()
{
    int no_of_pattern;
    cout << endl;
    cout << "Select which pattern you want to print from below list:\n";
    cout << endl;
    cout << "1. Inverted & Reverse Same Number Triangle Pattern (H.W-1)." << endl;
    cout << endl;
    cout << "2. Inverted Same Number Triangle Pattern (H.W-2)." << endl;
    cout << endl;
    cout << "3. Inverted Continuous Number Triangle Pattern (H.W-3)." << endl;
    cout << endl;
    cout << "4. Inverted & Reverse Number Triangle Pattern (H.W-4)." << endl;
    cout << endl;
    cin >> no_of_pattern;
    cout << endl;

    switch (no_of_pattern)
    {
    case 1:
        pattern1();
        break;

    case 2:
        pattern2();
        break;

    case 3:
        pattern3();
        break;

    case 4:
        pattern4();
        break;

    default:
        cout << "Invalid Number, please select a number from above given list :)" << endl;
        cout << endl;
    }

    return 0;
}

void pattern1()
{
    // Inverted Same Number Triangle Pattern
    cout << endl;
    cout << "You are going to see a inverted & reverse same number triangle pattern (H.W-1):- " << endl;

    int height, i, j, k, value = 1;
    char ch;
    cout << endl;
    cout << "Enter height of the triangle:- ";
    cout << endl;
    cin >> height;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        for (k = 1; k <= i; k++)
        {
            cout << "  ";
        }
        for (j = height; j >= i; j--)
        {
            cout << value << " ";
        }
        cout << endl;
        value++;
    }
    cout << endl;
}

void pattern2()
{
    // Inverted Same Number Triangle Pattern
    cout << endl;
    cout << "You are going to see a inverted same number triangle pattern (H.W-2):- " << endl;

    int height, i, j, k, value = 1;
    char ch;
    cout << endl;
    cout << "Enter height of the triangle:- ";
    cout << endl;
    cin >> height;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        for (k = 1; k <= (height - i); k++)
        {
            cout << "  ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << value << " ";
        }
        cout << endl;
        value++;
    }
    cout << endl;
}

void pattern3()
{
    // Continuous Number Triangle Pattern
    cout << endl;
    cout << "You are going to see a inverted continuous number triangle pattern (H.W-3):- " << endl;

    int height, i, j, k, value = 1;
    char ch;
    cout << endl;
    cout << "Enter height of the triangle:- ";
    cout << endl;
    cin >> height;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        for (k = 1; k <= (height - i); k++)
        {
            cout << "  ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << value << " ";
            value++;
        }
        cout << endl;
    }
    cout << endl;
}

void pattern4()
{
    // Continuous Number Triangle Pattern
    cout << endl;
    cout << "You are going to see a inverted & reverse continuous number triangle pattern (H.W-4):- " << endl;

    int height, i, j, k, value;
    char ch;
    cout << endl;
    cout << "Enter height of the triangle:- ";
    cout << endl;
    cin >> height;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        value = 1;
        for (k = 1; k <= i; k++)
        {
            cout << "  ";
        }
        for (j = height; j >= i; j--)
        {
            cout << value << " ";
            value++;
        }
        cout << endl;
    }
    cout << endl;
}