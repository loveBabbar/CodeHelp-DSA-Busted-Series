#include <iostream>
using namespace std;

void heapify(int *arr, int n, int i) {

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    // if largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {

    int size = n;

    while (size > 1) {

        // swap root with last element
        swap(arr[1], arr[size]);

        // decrease the size
        size = size - 1;

        // take root to its correct position
        heapify(arr, size, 1);
    }
}

int main() {

    // input array is 1-based indexing
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // build heap
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}