#include <iostream>
using namespace std;
int sumArray(int num[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += num[i];
    }
    return sum;
}
int main()
{
    int size;
    cin >> size;
    int num[100];

    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
     // int n = sizeof(num) / sizeof(num[0]);
    }
    cout << sumArray(num, size) << endl;
}
