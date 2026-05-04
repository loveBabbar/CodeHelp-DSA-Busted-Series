#include <bits/stdc++.h>
using namespace std;

class MySolution {
  public:
    int reccursion(vector<int>& arr, int n, int cur, int prev) {
        
        // TC: exponential

        if (cur == n) return 0;
        
        int take = 0; // **important '0'**
        if (prev == -1 || arr[cur] > arr[prev]) {
            take = 1 + reccursion(arr, n, cur+1, cur);
        }
        
        int not_take = 0 + reccursion(arr, n, cur+1, prev);
        
        return max(take, not_take);
    }
    
    int memoization(
        vector<int>& arr, 
        int n, 
        int cur, 
        int prev,
        vector<vector<int>> &dp
    ) {
        
        // TC: O(n**2)

        if (cur == n) return 0;
        
        // **prev = -1, -> look why
        if (dp[cur][prev+1] != -1) {
            return dp[cur][prev+1];
        }
        
        int take = 0; // **important '0'**
        if (prev == -1 || arr[cur] > arr[prev]) {
            take = 1 + memoization(arr, n, cur+1, cur, dp);
        }
        
        int not_take = 0 + memoization(arr, n, cur+1, prev, dp);
        
        // **prev = -1, -> look why
        return dp[cur][prev+1] = max(take, not_take);
    }
    
    int tabulation(vector<int>& arr) {
        
        // TC: O(n**2)
        
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // **base case: done**
        
        for (int cur = n-1; cur >= 0; cur--) {
            
            for (int prev = cur-1; prev >= -1; prev--) {
                
                int take = 0; // **important '0'**
                if (prev == -1 || arr[cur] > arr[prev]) {
                    take = 1 + dp[cur+1][cur+1];
                }
                
                int not_take = 0 + dp[cur+1][prev+1];
                
                dp[cur][prev+1] = max(take, not_take);
            }
        }
        return dp[0][0];
    }
    
    int space_optimised(vector<int>& arr) {
        
        // TC: O(n**2)
        int n = arr.size();
        
        vector<int> cur_row(n+1, 0);
        vector<int> next_row(n+1, 0);
        
        // **base case: done**
        
        for (int cur = n-1; cur >= 0; cur--) {
            
            for (int prev = cur-1; prev >= -1; prev--) {
                
                int take = 0; // **important '0'**
                if (prev == -1 || arr[cur] > arr[prev]) {
                    take = 1 + next_row[cur+1];
                }
                
                int not_take = 0 + next_row[prev+1];
                
                cur_row[prev+1] = max(take, not_take);
            }
            
            // **important**
            next_row = cur_row;
        }
        return next_row[0];
    }

    int dp_with_binary_search(int n, vector<int> a) {
        
        // TC: O(nlogn)
        if (n == 0) {
            return 0;
        }
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for (int i = 1; i < n; i++) {
            
            // push element in last in vector, 
            // if last element at last is < a[i]
            if (a[i] > ans.back()) {
                ans.push_back(a[i]);
            }
            else {
                
                // find index of just badda element
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
};

// ****starts from here****
class Solution {
private:
    MySolution solution;
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // return solution.space_optimised(nums);

        return solution.dp_with_binary_search(nums.size(), nums);
    }
};