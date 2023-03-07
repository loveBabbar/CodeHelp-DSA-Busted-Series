/*
@Reducing Dishes
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishesmultiplied by its satisfaction level
i.e. time[i] * satisfaction[i].
Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Example 1:
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.

*/

// CODE LINK : https://leetcode.com/problems/reducing-dishes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(vector<int> &satisfaction, int index, int time)
    {
        // base-case
        if (index == satisfaction.size())
        {
            return 0;
        }

        int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1);
        int exclude = 0 + solve(satisfaction, index + 1, time);

        return max(include, exclude);
    }
    // Approach-2 Using Recursion + Memoisation Using DP Array
    int solveMemo(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
    {
        // base-case
        if (index == satisfaction.size())
        {
            return 0;
        }

        if (dp[index][time] != -1)
        {
            return dp[index][time];
        }

        int include = satisfaction[index] * (time + 1) + solveMemo(satisfaction, index + 1, time + 1, dp);
        int exclude = 0 + solveMemo(satisfaction, index + 1, time, dp);

        return dp[index][time] = max(include, exclude);
    }
    // Approach-3 Using Bottom-up Approach Tabulation Method
    int solveTabulation(vector<int> &satisfaction)
    {
        int n = satisfaction.size();

        // step-1 creation of dp array
        // vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MIN));
        // dp[n][n] = 0;
        // OR
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
                int exclude = 0 + dp[index + 1][time];
                dp[index][time] = max(include, exclude);
            }
        }

        return dp[0][0]; // In top-down Both (index 0 - n-1) & (time 0 - n-1),therefore bottom up will be [0][0]
    }

    // Approach-4 Tabulation + Space Optimisation
    int solveTabulationSpaceOpt(vector<int> &satisfaction)
    {
        int n = satisfaction.size();

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = satisfaction[index] * (time + 1) + next[time + 1];
                int exclude = 0 + next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }

        return next[0];
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        // step-1 sort answer
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        // Approach-1
        return solve(satisfaction, 0, 0);

        // Approach-2
        // why size of n+1 ? because time is starting from 1 not 0, so time will go like 1,2,3...n size
        // but in indexing it goes like 0,1,2,3...n size
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solveMemo(satisfaction, 0, 0, dp);

        // Approach-3
        return solveTabulation(satisfaction);

        // Approach-4
        return solveTabulationSpaceOpt(satisfaction);
    }
};