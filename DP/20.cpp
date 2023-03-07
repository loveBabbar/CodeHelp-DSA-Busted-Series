/*
@ Pizza With 3n Slices

There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.

Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.

*/

// CODE LINK : https://leetcode.com/problems/pizza-with-3n-slices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(int index, int endIndex, vector<int> &slices, int n)
    {
        // base-case
        if (n == 0 || index > endIndex)
            return 0;

        int take = slices[index] + solve(index + 2, endIndex, slices, n - 1);
        int notTake = 0 + solve(index + 1, endIndex, slices, n);

        return max(take, notTake);
    }
    // Approach-2 Using Recursion + Memoisation
    int solveMemo(int index, int endIndex, vector<int> &slices, int n, vector<vector<int>> &dp)
    {
        // base-case
        if (n == 0 || index > endIndex)
            return 0;

        if (dp[index][n] != -1)
            return dp[index][n];

        int take = slices[index] + solveMemo(index + 2, endIndex, slices, n - 1, dp);
        int notTake = 0 + solveMemo(index + 1, endIndex, slices, n, dp);

        return dp[index][n] = max(take, notTake);
    }
    // Approach-3 Using Tabulation Method
    int solveTabulation(vector<int> &slices)
    {
        int k = slices.size();

        // note k+2 because in loop we are doing index+2, & we don't want index out of range/overflow error.
        vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

        for (int index = k - 2; index >= 0; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + dp1[index + 2][n - 1];
                int notTake = 0 + dp1[index + 1][n];
                dp1[index][n] = max(take, notTake);
            }
        }
        int case1 = dp1[0][k / 3]; // [0] because index increase ho raha taha [k/3] n decrease ho raha tha

        for (int index = k - 1; index >= 1; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + dp2[index + 2][n - 1];
                int notTake = 0 + dp2[index + 1][n];
                dp2[index][n] = max(take, notTake);
            }
        }
        int case2 = dp2[1][k / 3]; // [0] because index increase ho raha taha [k/3] n decrease ho raha tha

        return max(case1, case2);
    }
    // Approach-4 Using Tabulation + Space Optimisation
    int solveTabulationSpaceOpt(vector<int> &slices)
    {
        int k = slices.size();

        // note k+2 because in loop we are doing index+2, & we don't want index out of range/overflow error.
        vector<int> prev1(k + 2, 0);
        vector<int> curr1(k + 2, 0);
        vector<int> next1(k + 2, 0);

        vector<int> prev2(k + 2, 0);
        vector<int> curr2(k + 2, 0);
        vector<int> next2(k + 2, 0);

        for (int index = k - 2; index >= 0; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + next1[n - 1];
                int notTake = 0 + curr1[n];
                prev1[n] = max(take, notTake);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k / 3]; // har bar next lete thein this time 3 hain prev,curr,next that's why curr hoga like curr/next mein next lete thein , similary prev,curr,next mein curr le lenge

        for (int index = k - 1; index >= 1; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + next2[n - 1];
                int notTake = 0 + curr2[n];
                prev2[n] = max(take, notTake);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k / 3];

        return max(case1, case2);
    }
    int maxSizeSlices(vector<int> &slices)
    {
        // Approach-1
        int k = slices.size();
        int case1 = solve(0, k - 2, slices, k / 3);
        int case2 = solve(1, k - 1, slices, k / 3);
        return max(case1, case2);

        // Approach-2
        vector<vector<int>> dp1(k, vector<int>(k, -1));
        int case1 = solveMemo(0, k - 2, slices, k / 3, dp1);
        vector<vector<int>> dp2(k, vector<int>(k, -1));
        int case2 = solveMemo(1, k - 1, slices, k / 3, dp2);
        return max(case1, case2);

        // Approach-3
        return solveTabulation(slices);

        // Approach-4
        return solveTabulationSpaceOpt(slices);
    }
};