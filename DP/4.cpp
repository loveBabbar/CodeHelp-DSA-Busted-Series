/*
@ Max Sum without Adjacents

Example 1:
Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.

Example 2:
Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13

*/

// CODE LINK : https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion [i.e, Traversing From Left -> Right]
    int solve(int *arr, int n, int currIndex, int currSum)
    {
        // base-case
        if (currIndex > n - 1)
        {
            return currSum;
        }

        // Recursive calls
        int include = solve(arr, n, currIndex + 2, currSum + arr[currIndex]);
        int exclude = solve(arr, n, currIndex + 1, currSum + 0);

        // Return answer
        return max(include, exclude);
    }

    // Approach-2 Using Recursion + Memoisation [i.e, Traversing From Right -> Left]
    int solveMemo(int *arr, int n, vector<int> &dp)
    {
        // base-case
        if (n < 0)
            return 0;

        if (n == 0)
            return arr[0];

        // Returning Memoised value
        if (dp[n] != -1)
            return dp[n];

        int included = solveMemo(arr, n - 2) + arr[n];
        int excluded = solveMemo(arr, n - 1) + 0;

        dp[n] = max(included, excluded);

        return dp[n];
    }

    // Approach-3 Using Tabluation Method
    int solveTabulation(int *arr, int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            int included = dp[i - 2] + arr[i];
            int excluded = dp[i - 1] + 0;
            dp[i] = max(included, excluded);
        }

        return dp[n];
    }

    // Approach-4 Using Tabulation Method + Space Optmisatio Most Optimised Approch T.C -> O(n) S.C -> O(1)
    int solveTabulationSpaceOpt(int *arr, int n)
    {
        int prev1 = arr[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int include = prev2 + arr[i];
            int exclude = prev1 + 0;

            int curr = max(include, exclude);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    // calculate the maximum sum with out adjacent

    // Approach-1
    int findMaxSumWithRecursion(int *arr, int n)
    {
        return solve(arr, n);
    }

    // Approach-2
    int findMaxSumWithMemo(int *arr, int n)
    {
        vector<int> dp(n + 1, 0);
        return solveMemo(arr, n - 1, dp);
    }

    // Approach-3
    int findMaxSumUsingDP(int *arr, int n)
    {
        return solveTabulation(arr, n - 1);
    }

    // Approach-4
    int findMaxMostOptimised(int *arr, int n)
    {
        return solveTabulationSpaceOpt(arr, n);
    }
};