#include <iostream>
#include <heap>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
    
}

void heapSort(int arr[], int n) 
{
    int size = n;

    while (size > 1)
    {
        // step 1
        // swap

        swap(arr[1], arr[size]);

        // step 2
        size--;

        //step 3 - heapify

        heapify(arr, size, 1);
    }
    
}

int main(int argc, char const *argv[])
{

    int arr[6] = {};
    int n = 5;
    heapSort(arr, n);

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
    
    
    return 0;
}
