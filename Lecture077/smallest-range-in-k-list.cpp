#include <limits.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node(int data, int r, int c) {
        this->data = data;
        row = r;
        col = c;
    }
};

class compare {
public:

    // compare two nodes by there data values
    bool operator()(Node* first, Node* second) {
        return first->data > second->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    int mini = INT_MAX;
    int maxi = INT_MIN;

    // push first k elements into minheap,
    // with keep track of min/ max element
    for (int i = 0; i < k; i++) {

        mini = min(mini, a[i][0]);
        maxi = max(maxi, a[i][0]);
        minHeap.push(new Node(a[i][0], i, 0));
    }

    int start = mini, end = maxi;

    while (!minHeap.empty()) {
        Node* tmp = minHeap.top();
        minHeap.pop();

        mini = tmp->data;

        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        if (tmp->col + 1 < n) {
            maxi = max(maxi, a[tmp->row][tmp->col+1]);
            minHeap.push(new Node(a[tmp->row][tmp->col+1], tmp->row, tmp->col+1));
        }
        else {
            break;
        }
    }
    return end - start + 1;
}