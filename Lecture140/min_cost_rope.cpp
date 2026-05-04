// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minCost(vector<int>& arr) {
        
        // create min heap
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // push all the elements of the array to min heap
        for (auto i : arr) minHeap.push(i);
        
        // find the minimum cost
        int cost = 0;
        
        while (minHeap.size() > 1) {
            
            // pop two elements
            int first = minHeap.top();
            minHeap.pop();
            
            int second = minHeap.top();
            minHeap.pop();
            
            int sum = first + second;
            
            // note: these two elements are the samllest of the array
            cost += sum; 
            
            // push this sum to min heap
            minHeap.push(sum);
        }
        return cost;
    }
};