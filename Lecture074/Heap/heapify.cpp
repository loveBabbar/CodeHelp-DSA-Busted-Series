#include <iostream>
using namespace std;

class Heap {
private:
    int *arr;
    int capacity;
    int size;

public:
    Heap(int s) {
        capacity = s;
        size = 0;
        arr = new int[capacity];
    }

    void insert(int x) {
        if (size == capacity) {
            cout << "heap is full" << endl;
            return;
        }

        size = size + 1;
        int idx = size;
        arr[idx] = x;

        // swap node with its parent until the heap property is satisfied
        while (idx > 1) {

            // print();

            int parent = idx / 2;
            if (arr[parent] < arr[idx]) {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else {
                return;
            }
        }
    }

    void deleteRoot() {
        if (size == 0) {
            cout << "heap is empty" << endl;
            return;
        }

        // put last element at the root 
        arr[1] = arr[size];

        // decrease the size
        size = size - 1;

        // take root to its correct position
        int i = 1;
        while (i < size) {

            int left = 2 * i;
            int right = 2 * i + 1;

            if (left <= size && arr[left] > arr[i]) {
                swap(arr[left], arr[i]);
                i = left;
            }
            else if (right <= size && arr[right] > arr[i]) {
                swap(arr[right], arr[i]);
                i = right;
            }
            else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

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

int main() {

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}