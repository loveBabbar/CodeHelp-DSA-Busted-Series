// https://leetcode.com/problems/partition-equal-subset-sum/submissions/1965132330

#include <bits/stdc++.h>
using namespace std;

class MySolution {
  public:
    bool recursion(int index, vector<int>& arr, int N, int target) {
        
        if (index >= N) {
            return 0;
        }
        
        if (target < 0) return 0;
        
        if (target == 0) return 1;
        
        bool include = recursion(index+1, arr, N, target-arr[index]);
        bool exclude = recursion(index+1, arr, N, target);
        
        return include or exclude;
    }
    
    bool memoization(int index, vector<int>& arr, int N, int target, vector<vector<int>> &dp) {
        
        if (index >= N) {
            return 0;
        }
        
        if (target < 0) return 0;
        
        if (target == 0) return 1;
        
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        
        bool include = memoization(index+1, arr, N, target-arr[index], dp);
        bool exclude = memoization(index+1, arr, N, target, dp);
        
        return dp[index][target] = include or exclude;
    }

    bool tabulation(int n, vector<int> arr, int total) {
        
        vector<vector<int>> dp(n+1, vector<int> (total+1, 0));
        
        // **analysing base cases**
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int index = n-1; index >= 0; index--) {
            for (int target = 0; target <= total/2; target++) {
                
                bool include = false;
                
                if (target-arr[index] >= 0)
                    include = dp[index+1][target-arr[index]];
                    
                bool exclude = dp[index+1][target];
                
                dp[index][target] = include or exclude;
            }
        }
        return dp[0][total/2];
    }

    bool space_optimised(int n, vector<int> arr, int total) {
        
        vector<int> curr(total+1, 0);
        vector<int> next(total+1, 0);
        
        curr[0] = 1;
        next[0] = 1;
        
        for (int index = n-1; index >= 0; index--) {
            for (int target = 0; target <= total/2; target++) {
                
                bool include = false;
                
                if (target-arr[index] >= 0)
                    include = next[target-arr[index]];
                    
                bool exclude = next[target];
                
                curr[target] = include or exclude;
            }
            next = curr;
        }
        return next[total/2];
    }
};

class Solution {
private:
    MySolution solution;
public:
    bool canPartition(vector<int>& arr) {
        
        int total = 0;
        for (int i = 0; i < arr.size(); i++) {
            total += arr[i];
        }
        
        // sum is odd: means we cannot divide it in two parts
        if (total & 1) {
            return 0;
        }
        
        // sum to find in the array now
        int target = total / 2;
        
        // now instead of finding equalPartition find that target sum
        // exits in arr or not
        // return solution.recursion(0, arr, arr.size(), target);
        
        // vector<vector<int>> dp(arr.size(), vector<int> (target+1, -1));
        // return solution.memoization(0, arr, arr.size(), target, dp);

        // return solution.tabulation(arr.size(), arr, total);

        return solution.space_optimised(arr.size(), arr, total);
    }
};