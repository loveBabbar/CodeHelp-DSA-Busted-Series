// https://leetcode.com/problems/longest-arithmetic-subsequence/submissions/1966018776

#include <bits/stdc++.h>
using namespace std;

class BruteForce {
  private:
    // Recursive function to find AP length ending at 'index' with given 'diff'
    int solve(int index, int diff, vector<int>& arr) {
        
        if (index < 0) return 0;
        
        int ans = 0;
        
        // find all possible AP pairs before element at 'index'
        for (int j = index-1; j >= 0; j--) {
            
            if (arr[index] - arr[j] == diff)
                ans = max(ans, 1 + solve(j, diff, arr));
        }
        
        return ans;
    }
    
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        
        if (arr.size() <= 2) return arr.size();
        
        int ans = 0;
        
        // pick two elements from start to end, (explore all pairs)
        for (int i = 0; i < arr.size(); i++) {
            
            for (int j = i+1; j < arr.size(); j++) {
                
                ans = max(ans, 2 + solve(i, arr[j]-arr[i], arr));
            }
        }
        
        return ans;
        
    }
};

class Memoization {
    
    // Recursive function to find AP length ending at 'index' with given 'diff'
    int memoisation(int index, int diff, vector<int>& arr, unordered_map<int, int> dp[]) {
        
        if (index < 0) return 0;
        
        if (dp[index].count(diff)) {
            return dp[index][diff];
        }
        
        int ans = 0;
        
        // find all possible AP pairs before element at 'index'
        for (int j = index-1; j >= 0; j--) {
            
            if (arr[index] - arr[j] == diff)
                ans = max(ans, 1 + memoisation(j, diff, arr, dp));
        }
        
        return dp[index][diff] = ans;
    }
    
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        
        if (arr.size() <= 2) return arr.size();
        
        int ans = 0;
        
        unordered_map<int, int> dp[arr.size()];
        
        // pick two elements from start to end, (explore all pairs)
        for (int i = 0; i < arr.size(); i++) {
            
            for (int j = i+1; j < arr.size(); j++) {
                
                ans = max(ans, 2 + memoisation(i, arr[j]-arr[i], arr, dp));
            }
        }
        
        return ans;
    }
};

class Tabulation {
public:
    int solve(vector<int> &arr) {
        
        if (arr.size() < 2) return arr.size();
        
        int ans = 0;
        unordered_map<int, int> dp[arr.size()+1];
        
        for (int i = 1; i < arr.size(); i++) {
            
            for (int j = 0; j < i; j++) {
                
                int diff = arr[i] - arr[j];
                int cnt = 1;
                
                // already present
                if (dp[j].count(diff)) {
                    cnt = dp[j][diff];
                }
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};


class Solution {
    BruteForce brute_solution;
    Memoization memo_solution;
    Tabulation solution;
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        // return brute_solution.lengthOfLongestAP(nums);

        // return memo_solution.lengthOfLongestAP(nums);

        return solution.solve(nums);
    }
};