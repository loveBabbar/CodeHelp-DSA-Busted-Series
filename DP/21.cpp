/*
@ Number of Dice Rolls With Target Sum

Example 1:
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.

Example 2:
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

*/

// CODE LINK : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;

    // Approach-1 Using Normal Recursion
    int solve(int dices, int faces, int target)
    {
        // base-case
        if (target < 0)
        {
            return 0;
        }
        if (dices == 0 && target != 0)
        {
            return 0;
        }
        if (target == 0 && dices != 0)
        {
            return 0;
        }
        if (dices == 0 && target == 0)
        {
            return 1; // dices bhi over ho gye & target bhi 0 ho gya that's an answer
        }

        int ans = 0;
        for (int i = 1; i <= faces; i++)
        {
            ans = (ans % mod + solve(dices - 1, faces, target - i) % mod) % mod;
        }

        return ans;
    }
    // Approach-2 Using Recursion + Memoisation
    int solveMemo(int dices, int faces, int target, vector<vector<int>> &dp)
    {
        // base-case
        if (target < 0)
        {
            return 0;
        }
        if (dices == 0 && target != 0)
        {
            return 0;
        }
        if (target == 0 && dices != 0)
        {
            return 0;
        }
        if (dices == 0 && target == 0)
        {
            return 1;
        }

        if (dp[dices][target] != -1)
        {
            return dp[dices][target];
        }

        int ans = 0;
        for (int i = 1; i <= faces; i++)
        {
            ans = (ans % mod + solveMemo(dices - 1, faces, target - i, dp) % mod) % mod;
        }

        return dp[dices][target] = ans;
    }
    // Approach-3 Using Tabulation Method
    int solveTabulation(int d, int f, int t)
    {
        // step-1 creation of dp array
        vector<vector<int>> dp(d + 1, vector<int>(t + 1, 0));
        dp[0][0] = 1;

        for (int dices = 1; dices <= d; dices++)
        {
            for (int target = 1; target <= t; target++)
            {
                int ans = 0;
                for (int i = 1; i <= f; i++)
                {
                    if (target - i >= 0)
                    { // should be a valid index
                        ans = (ans % mod + dp[dices - 1][target - i] % mod) % mod;
                    }
                }
                dp[dices][target] = ans;
            }
        }

        return dp[d][t];
    }
    // Approach-4 Using Tabulation + Space Optimisation
    int solveTabulationSpaceOpt(int d, int f, int t)
    {
        vector<int> prev(t + 1, 0);
        vector<int> curr(t + 1, 0);

        // after analysing base case
        prev[0] = 1;

        for (int dices = 1; dices <= d; dices++)
        {
            for (int target = 1; target <= t; target++)
            {
                int ans = 0;
                for (int i = 1; i <= f; i++)
                {
                    if (target - i >= 0)
                    {
                        ans = (ans % mod + prev[target - i] % mod) % mod;
                    }
                }
                curr[target] = ans;
            }
            prev = curr;
        }

        return prev[t]; // let's say there are 3 dices , therefore after 3 iteretions current mein change ho chuka hoga due to curr[target] = ans; & finally prev -> curr sahi postion par hoga.
    }
    int numRollsToTarget(int n, int k, int target)
    {
        // Approach-1
        return solve(n, k, target);

        // Approach-2
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solveMemo(n, k, target, dp);

        // Approach-3
        return solveTabulation(n, k, target);

        // Approach-4
        return solveTabulationSpaceOpt(n, k, target);
    }
};