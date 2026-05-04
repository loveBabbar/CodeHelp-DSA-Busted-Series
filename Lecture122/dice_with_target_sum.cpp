// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/submissions/1964771953

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class MySolution {
  public:
    int recursion(int faces, int total_dice, int target_sum) {
        
        // **base cases**
        
        if (target_sum < 0) {
            return 0;
        }
        
        if (total_dice == 0 && target_sum != 0) {
            return 0;
        }
        
        // one way found
        if (total_dice == 0 && target_sum == 0) {
            return 1;
        }
        
        int no_of_ways = 0;
        
        // go one by one in all faces
        for (int face = 1; face <= faces; face++) {
            
            no_of_ways = no_of_ways + recursion(faces, total_dice-1, target_sum-face);
        }
        
        // cout << no_of_ways << face << " " << target_sum << endl;
        return no_of_ways % MOD;
    }
    
    
    int memoization(int faces, int total_dice, int target_sum, vector<vector<int>> &dp) {
        
        // **base cases**
        
        if (target_sum < 0) {
            return 0;
        }
        
        if (total_dice == 0 && target_sum != 0) {
            return 0;
        }
        
        // one way found
        if (total_dice == 0 && target_sum == 0) {
            return 1;
        }
        
        if (dp[total_dice % MOD][target_sum % MOD] != -1) {
            return dp[total_dice % MOD][target_sum % MOD];
        }
        
        int no_of_ways = 0;
        
        // go one by one in all faces
        for (int face = 1; face <= faces; face++) {
            
            no_of_ways = no_of_ways % MOD + memoization(faces, total_dice-1, target_sum-face, dp) 
                                                % MOD;
        }
        
        // cout << no_of_ways << face << " " << target_sum << endl;
        return dp[total_dice % MOD][target_sum % MOD] = no_of_ways % MOD;
    }

    int tabulation(int faces, int total_dice, int target_sum) {
        
        vector<vector<int>> dp(total_dice+1, vector<int> (target_sum+1, 0));
        
        // **by analysing all base cases**
        dp[0][0] = 1;
        
        for (int dice = 1; dice <= total_dice; dice++) {
            for (int sum = 1; sum <= target_sum; sum++) {
            
                int no_of_ways = 0;
        
                // go one by one in all faces
                for (int face = 1; face <= faces; face++) {
                    
                    if (sum - face >= 0)
                        no_of_ways = (no_of_ways + dp[dice-1][sum-face]) % MOD;
                }
                
                dp[dice][sum] = no_of_ways; 
            }
        }
        return dp[total_dice][target_sum];
    }

    int space_optimisation(int faces, int total_dice, int target_sum) {
        
        vector<int> prev(target_sum+1, 0);
        vector<int> curr(target_sum+1, 0);
        
        // **by analysing all base cases**
        prev[0] = 1;
        
        for (int dice = 1; dice <= total_dice; dice++) {
            for (int sum = 1; sum <= target_sum; sum++) {
            
                int no_of_ways = 0;
        
                // go one by one in all faces
                for (int face = 1; face <= faces; face++) {
                    
                    if (sum - face >= 0)
                        no_of_ways = (no_of_ways + prev[sum-face]) % MOD;
                }
                
                curr[sum] = no_of_ways; 
            }
            prev = curr;
        }
        return prev[target_sum];
    }
};


class Solution {
private:
    MySolution solution;
public:
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        // return solution.memoization(k, n, target, dp);
        
        // return solution.tabulation(k, n, target);

        return solution.space_optimisation(k, n, target);
    }
};