// max heap and min heap by priority queue

#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> maxHeap; // by default, priority queue is a max heap
    maxHeap.push(40);
    maxHeap.push(20);
    maxHeap.push(60);

    cout << "max heap: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap
    minHeap.push(40);
    minHeap.push(20);
    minHeap.push(60);

    cout << "min heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}