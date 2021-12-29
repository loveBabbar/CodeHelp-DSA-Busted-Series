#include <iostream>

using namespace std;

void pattern1();
void pattern2();
void pattern3();
void pattern4();
void pattern5();
void pattern6();
void pattern7();
void pattern8();
void pattern9();
void pattern10();
void pattern11();
void pattern12();
void pattern13();
void pattern14();
void pattern15();

int main()
{
    int no_of_pattern;
    cout << endl;
    cout << "Select which pattern you want to print from below list:\n";
    cout << endl;
    cout << "1. Square Pattern." << endl;
    cout << endl;
    cout << "2. Number Square Pattern." << endl;
    cout << endl;
    cout << "3. Another Number Square Pattern." << endl;
    cout << endl;
    cout << "4. Inverted Number Square Pattern." << endl;
    cout << endl;
    cout << "5. Counting Square Pattern." << endl;
    cout << endl;
    cout << "6. 90 Degree Triangle Pattern." << endl;
    cout << endl;
    cout << "7. 90 Degree Counting Triangle Pattern." << endl;
    cout << endl;
    cout << "8. 90 Degree Inverted Counting Triangle Pattern." << endl;
    cout << endl;
    cout << "9. Alphabetic Square Pattern." << endl;
    cout << endl;
    cout << "10. Alphabetic Triangle Pattern." << endl;
    cout << endl;
    cout << "11. Inverted Alphabetic Triangle Pattern." << endl;
    cout << endl;
    cout << "12. Right Angle Inverted Character Triangle Pattern." << endl;
    cout << endl;
    cout << "13. Right Angle Reverse Character Triangle Pattern." << endl;
    cout << endl;
    cout << "14. Number Pyramid Pattern." << endl;
    cout << endl;
    cout << "15. Dabangg Pattern." << endl;
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

    case 5:
        pattern5();
        break;

    case 6:
        pattern6();
        break;

    case 7:
        pattern7();
        break;

    case 8:
        pattern8();
        break;

    case 9:
        pattern9();
        break;

    case 10:
        pattern10();
        break;

    case 11:
        pattern11();
        break;

    case 12:
        pattern12();
        break;

    case 13:
        pattern13();
        break;

    case 14:
        pattern14();
        break;

    case 15:
        pattern15();
        break;

    default:
        cout << "Invalid Number, please select a number from above given list :)" << endl;
        cout << endl;
    }

    return 0;
}

void pattern1()
{
    // Square Pattern
    cout << endl;
    cout << "You are going to see a square pattern:- " << endl;

    int side, i, j;
    cout << endl;
    cout << "Enter side of the square:";
    cout << endl;
    cin >> side;
    cout << endl;

    for (i = 1; i <= side; i++)
    {
        for (j = 1; j <= side; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern2()
{
    // Number Square Pattern
    cout << endl;
    cout << "You are going to see a number square pattern:- " << endl;

    int side, i, j;
    cout << endl;
    cout << "Enter side of the square:";
    cout << endl;
    cin >> side;
    cout << endl;

    for (i = 1; i <= side; i++)
    {
        for (j = 1; j <= side; j++)
        {
            cout << i << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern3()
{
    // Number Square Pattern - Part 2
    cout << endl;
    cout << "You are going to see another version of number square pattern:- " << endl;

    int side, i, j;
    cout << endl;
    cout << "Enter side of the square:";
    cout << endl;
    cin >> side;
    cout << endl;

    for (i = 1; i <= side; i++)
    {
        for (j = 1; j <= side; j++)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern4()
{
    // Inverted Number Square Pattern
    cout << endl;
    cout << "You are going to see inverted number square pattern:- " << endl;

    int side, i, j;
    cout << endl;
    cout << "Enter side of the square:";
    cout << endl;
    cin >> side;
    cout << endl;

    for (i = 1; i <= side; i++)
    {
        for (j = 1; j <= side; j++)
        {
            cout << (side - j + 1) << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern5()
{
    // Counting Square Pattern
    cout << endl;
    cout << "You are going to see counting square pattern:- " << endl;

    int side, i, j, counter = 1;
    cout << endl;
    cout << "Enter side of the square:";
    cout << endl;
    cin >> side;
    cout << endl;

    for (i = 1; i <= side; i++)
    {
        for (j = 1; j <= side; j++)
        {
            cout << counter << "  ";
            counter++;
        }
        cout << endl;
    }
    cout << endl;
}

void pattern6()
{
    // Right Angled Triangle Pattern
    cout << endl;
    cout << "You are going to see right angled triangle pattern:- " << endl;

    int height, i, j;
    char ch;
    cout << endl;
    cout << "Enter height of the triangle:";
    cout << endl;
    cin >> height;
    cout << endl;
    cout << "Enter the symbol of which you want to create the triangle also:- ";
    cout << endl;
    cin >> ch;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << ch << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern7()
{
    // Right Angled Counting Triangle Pattern
    cout << endl;
    cout << "You are going to see right angled triangle pattern:- " << endl;

    int height, i, j, k, counting = 1;
    char ch;
    cout << endl;
    cout << "Enter height of the triangle:";
    cout << endl;
    cin >> height;
    cout << endl;
    cout << "Enter the symbol of which you want to create the triangle:- ";
    cout << endl;
    cin >> ch;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        int value = i;
        for (j = 1; j <= i; j++)
        {
            cout << value << " ";
            value++;
        }
        cout << endl;
    }
    cout << endl;
}

void pattern8()
{
    // Right Angled Inverted Counting Triangle Pattern
    cout << endl;
    cout << "You are going to see right angled inverted triangle pattern:- " << endl;

    int height, i, j, val, k;
    char ch;
    cout << endl;
    cout << "Enter height of the triangle:";
    cout << endl;
    cin >> height;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << i - j + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern9()
{
    // Alphabetic Square Pattern
    cout << endl;
    cout << "You are going to see alphabetic square pattern:- " << endl;

    int side, i, j;
    char ch = 'A'; //* (For printing same alphabets in the rows)
    cout << endl;
    cout << "Enter side of the square:-";
    cout << endl;
    cin >> side;
    cout << endl;

    for (i = 1; i <= side; i++)
    {
        //! char ch = 'A';   (For Printing continuous aplhabetic order)
        for (j = 1; j <= side; j++)
        {
            cout << ch << " ";
            //! ch++;
        }
        cout << endl;
        ch++;
    }
    cout << endl;
}

void pattern10()
{
    // Alphabetic Triangle Pattern
    cout << endl;
    cout << "You are going to see alphabetic triangle pattern:- " << endl;

    int height, i, j;
    char ch = 'A'; //* (For printing same alphabets in the rows)
    cout << endl;
    cout << "Enter height of the triangle:-";
    cout << endl;
    cin >> height;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        //! char ch = 'A'; // (For Printing continuous aplhabetic order)
        for (j = 1; j <= i; j++)
        {
            cout << ch << " ";
            //! ch++; // (For Printing continuous aplhabetic order)
        }
        cout << endl;
        ch++; //* (For printing same alphabets in the rows)
    }
    cout << endl;
}

void pattern11()
{
    // Inverted Alphabetic Triangle Pattern
    cout << endl;
    cout << "You are going to see inverted alphabetic triangle pattern:- " << endl;

    int height, i, j;
    char value, ch = 'A';
    cout << endl;
    cout << "Enter height of the triangle:-";
    cout << endl;
    cin >> height;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        value = ch + height - i;
        for (j = 1; j <= i; j++)
        {
            cout << value << "  ";
            value++;
        }
        cout << endl;
    }
    cout << endl;
}

void pattern12()
{
    // Inverted Right Angle Character Triangle Pattern
    cout << endl;
    cout << "You are going to see inverted right angle triangle character pattern:- " << endl;

    int height, i, j, k;
    char ch;
    cout << endl;
    cout << "Enter height of the triangle:";
    cout << endl;
    cin >> height;
    cout << endl;
    cout << "Enter the symbol of which you want to create the triangle:- ";
    cout << endl;
    cin >> ch;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        for (k = 1; k <= (height - i); k++)
        {
            cout << "  ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern13()
{
    // Reverse Right Angle Character Triangle Pattern
    cout << endl;
    cout << "You are going to see reverse right angle triangle character pattern:- " << endl;

    int height, i, j;
    char ch;
    cout << endl;
    cout << "Enter height of the triangle:- ";
    cout << endl;
    cin >> height;
    cout << endl;
    cout << "Enter the symbol of which you want to create the triangle:- ";
    cout << endl;
    cin >> ch;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        /* for (j = 1; j <= (height - i + 1); j++)
        {
            cout << ch << " ";
        } */
        for (j = height; j >= i; j--)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern14()
{
    // Number Pyramid Pattern
    cout << endl;
    cout << "You are going to see a number pyramid pattern:- " << endl;

    int height, i, j, k, l;
    cout << endl;
    cout << "Enter height of the pyramid:- ";
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
            cout << j << " ";
        }
        for (l = i - 1; l >= 1; l--)
        {
            cout << l << " ";
        }
        cout << endl;
    }
}

void pattern15()
{
    // Dabangg Pattern
    cout << endl;
    cout << "You are going to see dabangg pattern:- " << endl;

    int height, i, j, k, l;
    cout << endl;
    cout << "Enter height of the pattern:- ";
    cout << endl;
    cin >> height;
    cout << endl;

    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= (height - i + 1); j++)
        {
            cout << j << " ";
        }
        for (k = 1; k <= (i - 1); k++)
        {
            cout << "* ";
        }
        for (k = (i - 1); k >= 1; k--)
        {
            cout << "* ";
        }
        for (l = (height - i + 1); l >= 1; l--)
        {
            cout << l << " ";
        }
        cout << endl;
    }
}