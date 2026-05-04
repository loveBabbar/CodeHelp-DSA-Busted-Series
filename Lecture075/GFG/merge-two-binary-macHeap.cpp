#include <bits/stdc++.h>

using namespace std; 

class Solution {
private:

    void heapify(vector<int> &arr, int n, int i) {

        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[left] > arr[largest])
            largest = left;

        if(right < n && arr[right] > arr[largest])
            largest = right;

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

public:

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {

        vector<int> ans;

        // merge arrays
        for(auto x : a) ans.push_back(x);
        for(auto x : b) ans.push_back(x);

        int size = ans.size();

        // build max heap
        for(int i = size/2 - 1; i >= 0; i--){
            heapify(ans, size, i);
        }

        return ans;
    }
};