// https://www.naukri.com/code360/problems/build-min-heap_1171167

#include <bits/stdc++.h> 
using namespace std;
void heapify(vector<int> &arr, int n, int i);

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for (int i = (n / 2)-1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}

void heapify(vector<int> &arr, int n, int i) {

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // if largest is not the root, swap and continue heapifying
    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}
