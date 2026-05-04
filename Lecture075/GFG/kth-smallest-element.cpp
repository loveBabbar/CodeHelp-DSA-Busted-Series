#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code 
        
        // create a maxHeap
        priority_queue<int> maxHeap;
        
        // push first k element into the heap
        for (int i = 0; i < k; i++) {
            maxHeap.push(arr[i]);
        }
        
        // traverse the remaining elements,
        // if found smaller element than root of maxHeap,
        // pop from heap, and push new element to heap
        for (int i = k; i < arr.size(); i++) {
            
            if (arr[i] < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        
        // now heap is containg first kth smallest elements,
        int ans = maxHeap.top();
        return ans;
    }
};