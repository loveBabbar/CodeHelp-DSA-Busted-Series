/*
@ Fibonacci Number

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

*/

// CODE LINK : https://leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }

        int ans = fib(n - 1) + fib(n - 2);

        return ans;
    }
    // Approach-2 Using Recursion + Memoisation
    int solveMemo(int n, vector<int> &dp)
    {
        // step-1
        if (n <= 1)
        {
            return n;
        }

        // step-3
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // step-2
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
    // Approach-3 Using Tabluation Method
    int solveTabulation(int n)
    {
        // step-1 creation of dp array
        vector<int> dp(n + 1);

        // step-2 fill dp by analysing the dp array
        dp[0] = 0;
        dp[1] = 1;

        // step-3
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    // Approach-2 Using Tabulation + Space Optimisation
    int solveTabulationSpaceOpt(int n)
    {
        int prev1 = 0;
        int prev2 = 1;

        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
    int fib(int n)
    {

        // Approach-1
        return solve(n);

        // Approach-3
        return solveTabulation(n);

        // Approach-4
        return solveTabulationSpaceOpt(n);

        // Approach-2
        vector<int> dp(n + 1);
        return solveMemo(n, dp);
    }
};