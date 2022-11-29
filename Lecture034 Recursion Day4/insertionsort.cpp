#include<iostream>
using namespace std;

void RecursiveInsertionSort(int* arr, int size)
{
    // Base case - already sorted
    if(size == 0 || size == 1)
    {
        return ;
    }

    //Recursive Call
    RecursiveInsertionSort(arr, size-1);

    int i, j;
    int temp = arr[size - 1];

    for(j = size - 2; j >= 0; j--)
    {
        if(arr[j] > temp)
        {
            arr[j + 1] = arr[j];
        }
        else
        {
            break;
        }
    }
    arr[j + 1] = temp;
}

int main()
{
    int arr[] = {8, 6, 3, 2, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    RecursiveInsertionSort(arr, size);

    // Printing elements
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
