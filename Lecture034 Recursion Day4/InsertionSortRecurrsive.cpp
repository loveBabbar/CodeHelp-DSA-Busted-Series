#include<iostream>
using namespace std;

void insertionSortRecursive(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;

    // Sort first n-1 elements
    insertionSortRecursive(arr, n - 1);

    // Insert last element at its correct position
    // in sorted array.
    int lastElement = arr[n - 1];
    int j = n - 2;

    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > lastElement)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = lastElement;
}

void printArray(int arr[] ,int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){

    int arr[] = {2,1,3,4,6,5};
    int size = 6;
    insertionSortRecursive(arr, n);
    printArray(arr, size);

    return 0;
}
