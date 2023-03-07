/*
@ Maximize The Cut Segments

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
Example 2:

Input:
N = 5
x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.

*/

// CODE LINK : https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion i.e, TLE Error
    int solve(int n, int x, int y, int z)
    {
        if (n == 0)
            return 0;

        if (n < 0)
            return INT_MIN;

        int ans1 = solve(n - x, x, y, z) + 1;
        int ans2 = solve(n - y, x, y, z) + 1;
        int ans3 = solve(n - z, x, y, z) + 1;

        return max(ans1, max(ans2, ans3));
    }
    // Approach-2 Using Recursion + Memoisation
    int solveMemo(int n, int x, int y, int z, vector<int> &dp)
    {
        if (n == 0)
            return 0;

        if (n < 0)
            return INT_MIN;

        if (dp[n] != -1)
            return dp[n];

        int ans1 = solveMemo(n - x, x, y, z, dp) + 1;
        int ans2 = solveMemo(n - y, x, y, z, dp) + 1;
        int ans3 = solveMemo(n - z, x, y, z, dp) + 1;

        dp[n] = max(ans1, max(ans2, ans3));
        return dp[n];
    }

    // Approach-3 Using Tabulation Method
    int solveTabulation(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, INT_MIN);

        // step-1
        dp[0] = 0;

        // step-2
        for (int i = 1; i <= n; i++)
        {
            if (i - x >= 0)
                dp[i] = max(dp[i], dp[i - x] + 1);

            if (i - y >= 0)
                dp[i] = max(dp[i], dp[i - y] + 1);

            if (i - z >= 0)
                dp[i] = max(dp[i], dp[i - z] + 1);
        }

        return dp[n];
    }

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int ans;
        // Approach-1
        ans = solve(n, x, y, z);

        // Approach-2
        vector<int> dp(n + 1, -1);
        ans = solveMemo(n, x, y, z, dp);

        // Approach-3
        ans = solveTabulation(n, x, y, z);
        return ans < 0 ? 0 : ans;

        // Note Space Optimistion is not possible here as the value of x , y and z can be varied according to the quesiton.
    }
};
