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

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    Heap h(10);
    h.insert(50);
    h.insert(52);
    h.insert(30);
    h.insert(60);

    h.print();

    return 0;
}