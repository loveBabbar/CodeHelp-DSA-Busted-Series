/*
@ Coin Change

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

*/

// CODE LINK : https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(vector<int> &coins, int amount)
    {
        // base-case
        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX;

        // Assuming minimum coins required to INT_MAX
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solve(coins, amount - coins[i]);
            if (ans != INT_MAX)
                mini = min(mini, 1 + ans);
        }

        return mini;
    }

    // Approach-2 Using Recursion + Memoisation
    int solveMemo(vector<int> &coins, int amount, vector<int> &dp)
    {
        // base-case
        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX;

        // Check if answer amount already exist in DP or not
        if (dp[amount] != INT_MAX)
            return dp[amount];

        // Assuming minimum coins required to INT_MAX
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveMemo(coins, amount - coins[i]);
            if (ans != INT_MAX)
                mini = min(mini, 1 + ans);
        }

        // Storing answer in DP Array
        dp[amount] = mini;

        // Returning answer
        return dp[amount];
    }

    // Approach-3 [Tabulation Method]
    int solveTabulation(vector<int> &coins, int amount)
    {
        // base-initialisations
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            // Trying to solve every amount figure from 1 - amount.
            for (int j = 0; j < coins.size(); j++)
            {
                // Trying each coin from every amount that is being figured
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        if (dp[amount] == INT_MAX)
            return -1;

        return dp[amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {

        int ans;

        // Approach-1
        ans = solve(coins, amount);
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;

        // Approach-2
        vector<int> dp(amount + 1, INT_MAX);
        ans = solveMemo(coins, amount, dp);
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;

        // Approach-3
        return solveTabulation(coins, amount);
    }
};