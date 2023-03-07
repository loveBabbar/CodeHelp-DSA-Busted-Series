/*
@ Minimum Score Triangulation of Polygon

Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

Input: values = [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

*/

// CODE LINK : https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(vector<int> &v, int i, int j)
    {
        // base-case
        if (i + 1 == j)
            return 0;

        int ans = INT_MAX;
        // Trying all the possible trinangles i+1 to <j
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, v[i] * v[j] * v[k] + solve(v, i, k) + solve(v, k, j));
        }

        return ans;
    }
    // Approach-2 Using Recursiion + Memoisation
    int solveMemo(vector<int> &v, int i, int j, vector<vector<int>> &dp)
    {
        // base-case
        if (i + 1 == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, v[i] * v[j] * v[k] + solveMemo(v, i, k, dp) + solveMemo(v, k, j, dp));
        }

        dp[i][j] = ans;

        return dp[i][j];
    }
    // Approach-3 Using Bottom-Up Tabulation Method
    int solveTabulation(vector<int> &v)
    {
        int n = v.size();
        // already 0 fill kar diya that's why not analysing base condition
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // bottom-up approach reverse loop
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }
    // Approach-4 Space Optimisation is not possible as there is nothing common.
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        // Appraoch-1
        return solve(values, 0, n - 1);

        // Approach-2
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // n or n+1 size both works fine as passing j = n-1;
        return solveMemo(values, 0, n - 1, dp);

        // Appraoch-3
        return solveTabulation(values);
    }
};