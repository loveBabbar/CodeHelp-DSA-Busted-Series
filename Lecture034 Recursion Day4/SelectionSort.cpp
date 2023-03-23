#include <bits/stdc++.h>
using namespace std;
void selection(int *arr, int index, int n)
{
    if (index == n)
    {
        return;
    }
    int min = index;
    for (int i = index + 1; i < n; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    swap(arr[min], arr[index]);
    selection(arr, index + 1, n);
}

int main()
{
    int arr[5] = {5, 3, 4, 1, 2};
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    selection(arr, 0, 5);
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
