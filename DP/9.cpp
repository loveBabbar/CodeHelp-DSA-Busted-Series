/*

@ 0 - 1 Knapsack Problem

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:
Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

Example 2:
Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0

*/

// @2D-DP ARRAY QUESTION GALTI SE 1DP ARRAY MEIN INCLUDE HO GYA HAIN !
// CODE LINK : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(int weight[], int value[], int index, int capacity)
    {
        // base-case if only 1 item to steal , then just compare its weight with the knapsack capacity
        if (index == 0)
        {
            if (weight[0] <= capacity)
            {
                return value[0];
            }
            else
            {
                return 0;
            }
        }

        int include = 0;
        if (weight[index] <= capacity)
        {
            include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
        }
        int exclude = 0 + solve(weight, value, index - 1, capacity);

        return max(include, exclude);
    }

    // Approach-2 Using Recursion + Memoisation
    int solveMemo(int weight[], int value[], int index, int capacity, int **dp)
    {
        // step-1 base-case
        if (index == 0)
        {
            if (weight[0] <= capacity)
            {
                return value[0];
            }
            else
            {
                return 0;
            }
        }

        // step-3
        if (dp[index][capacity] != -1)
            return dp[index][capacity];

        // step-2
        int include = 0;
        if (weight[index] <= capacity)
            include = value[index] + solveMemo(weight, value, index - 1, capacity - weight[index], dp);

        int exclude = 0 + solveMemo(weight, value, index - 1, capacity, dp);

        dp[index][capacity] = max(include, exclude);

        return dp[index][capacity];
    }

    // Approach-3 Using Tabulation Method
    int solveUsingTab(int weight[], int value[], int n, int capacity)
    {

        // step-1 creation of dp array
        int **dp;
        dp = new int *[n]; // *[*ptr1,*ptr2]

        // loop to create the table dynamically
        for (int i = 0; i < n; i++)
            dp[i] = new int[capacity + 1]; // *[*[],*[]]

        // loop to initially filled the table with -1
        for (int i = 0; i < n; i++)
            for (int j = 0; j < capacity + 1; j++)
                dp[i][j] = 0;

        // step-2 base-case values for dp
        for (int w = weight[0]; w <= capacity; w++)
        {
            if (weight[0] <= capacity)
            {
                dp[0][w] = value[0];
            }
            else
            {
                dp[0][w] = 0;
            }
        }

        // step-3
        for (int index = 1; index < n; index++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                int include = 0;
                if (weight[index] <= w)
                {
                    include = value[index] + dp[index - 1][w - weight[index]];
                }
                int exclude = 0 + dp[index - 1][w];

                dp[index][w] = max(include, exclude);
            }
        }

        return dp[n - 1][capacity];
    }

    // Approach-4 Space Optimisation
    int solveUsingTabSpaceOpt(int weight[], int value[], int n, int capacity)
    {

        // step-1
        vector<int> prev(capacity + 1, 0);
        vector<int> curr(capacity + 1, 0);

        // step-2 base-case values
        for (int w = weight[0]; w <= capacity; w++)
        {
            if (weight[0] <= capacity)
            {
                prev[w] = value[0];
            }
            else
            {
                prev[w] = 0;
            }
        }

        // step-3
        for (int index = 1; index < n; index++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                int include = 0;
                if (weight[index] <= w)
                {
                    include = value[index] + prev[w - weight[index]];
                }
                int exclude = 0 + prev[w];

                curr[w] = max(include, exclude);
            }
            prev = curr;
        }

        return prev[capacity];
    }

    // Approach-5 Space Optimisation
    int solveUsingTabSpaceOpt2(int weight[], int value[], int n, int capacity)
    {

        // step-1
        vector<int> curr(capacity + 1, 0);

        // step-2 base-case values for dp
        for (int w = weight[0]; w <= capacity; w++)
        {
            if (weight[0] <= capacity)
            {
                curr[w] = value[0];
            }
            else
            {
                curr[w] = 0;
            }
        }

        // step-3
        for (int index = 1; index < n; index++)
        {
            // here we are decreasing w-- from right to left , because ans depends of either curr[w] or curr[range 0 to w - weight[index]] which lies on left and side therefore if we consider itertion from left to right there might possiblity that we may overwirte values which can lead to wrong answer hence we are starting from right to left.
            for (int w = capacity; w >= 0; w--)
            {
                int include = 0;
                if (weight[index] <= w)
                {
                    include = value[index] + curr[w - weight[index]];
                }
                int exclude = 0 + curr[w];

                curr[w] = max(include, exclude);
            }
        }

        return curr[capacity];
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        int **dp;
        dp = new int *[n]; // *[*ptr1,*ptr2]

        // loop to create the table dynamically
        for (int i = 0; i < n; i++)
            dp[i] = new int[W + 1]; // *[*[],*[]]

        // loop to initially filled the table with -1
        for (int i = 0; i < n; i++)
            for (int j = 0; j < W + 1; j++)
                dp[i][j] = -1;

        // Approach-1
        return solve(wt, val, n - 1, W);

        // Approach-2
        return solveMemo(wt, val, n - 1, W, dp);

        // Approach-3
        return solveUsingTab(wt, val, n, W);

        // Approach-4
        return solveUsingTabSpaceOpt(wt, val, n, W);

        // Approach-5
        return solveUsingTabSpaceOpt2(wt, val, n, W);
    }
};
