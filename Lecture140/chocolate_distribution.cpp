// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        
        sort(a.begin(), a.end());
        
        int i = 0;
        int j = m - 1;
        
        int mini = INT_MAX;
        
        while (j < a.size()) {
            
            int diff = a[j] - a[i];
            
            mini = min(mini, diff);
            
            i++;
            j++;
        }
        
        return mini;
    }
};