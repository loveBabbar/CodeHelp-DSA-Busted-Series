/*
@ Min Cost Climbing Stairs

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

*/

// CODE LINK : https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(vector<int> &cost, int n)
    {
        if (n == 0)
            return cost[0];

        if (n == 1)
            return cost[1];

        return cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
    }
    // Approach-2 Using Recursion + Memoisation
    int solveMemo(vector<int> &cost, int n, vector<int> &dp)
    {
        if (n == 0)
            return cost[0];

        if (n == 1)
            return cost[1];

        if (dp[n] != -1)
            return dp[n];

        dp[n] = cost[n] + min(solveMemo(cost, n - 1, dp), solveMemo(cost, n - 2, dp));

        return dp[n];
    }
    // Approach-3 Using Tabulation Method
    int solveTabulation(vector<int> &cost, int n)
    {
        vector<int> dp(n + 1, 0);

        int dp[0] = cost[0];
        int dp[1] = cost[1];

        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]); // as we are going in increasing order therefore answer will be at last that is dp[n-1] & dp[n-2]
    }
    // Approach-2 Using Tabulation + Space Optimisation
    int solveTabulationSpaceOpt(vector<int> &cost, int n)
    {
        int prev1 = cost[0];
        int prev2 = cost[1];

        for (int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }

        return min(prev1, prev2);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int ans;

        // Approach-1
        ans = min(solve(cost, n - 1), solve(cost, n - 2));

        // Approach-3
        ans = solveTabulation(cost, n);

        // Approach-4
        ans = solveTabulationSpaceOpt(cost, n);

        // Approach-2
        vector<int> dp(n + 1, -1);
        ans = min(solveMemo(cost, n - 1, dp), solveMemo(cost, n - 2, dp));
    }
};