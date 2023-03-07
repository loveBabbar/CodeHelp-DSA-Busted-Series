/*
@ Longest Increasing Subsequence

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

// CODE LINK : https://leetcode.com/problems/longest-increasing-subsequence/description/
// VERY IMPORTANT : Solve the same question based on this pattern which is russian dolls envelopes

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(vector<int> &nums, int curr, int prev)
    {
        // base-case
        if (curr == nums.size())
        {
            return 0;
        }

        // include
        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev])
            include = 1 + solve(nums, curr + 1, curr);

        // exclude
        int exclude = 0 + solve(nums, curr + 1, prev);

        return max(include, exclude);
    }
    // Approach-2 Using Recursion + Memoisation Using DP Array
    int solveMemo(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
    {
        // base-case
        if (curr == nums.size())
        {
            return 0;
        }

        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1]; // prev+1 because of prev initial value which is -1
        }

        // include
        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev])
            include = 1 + solveMemo(nums, curr + 1, curr, dp);

        // exclude
        int exclude = 0 + solveMemo(nums, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(include, exclude);
    }
    // Approach-3 Using Tabluation Method
    int solveTabulation(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        // step-1 creation of dp array
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // here curr is of n+1 size
        // because in-last execution, Accessing dp[curr+1][xyz] curr+1 may lead to overflow index error

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // include
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev])
                {
                    include = 1 + dp[curr + 1][curr + 1]; // prev+1, because there might be the case
                    // where we may try to access dp[curr][-1] postion which may lead to overflow
                    // not curr + 1 , actually represents prev because of fact previous becomes current.
                }
                // exclude
                int exclude = 0 + dp[curr + 1][prev + 1]; // prev+1, because there might be the case where we
                // may try to access dp[curr][-1] postion which may lead to overflow

                dp[curr][prev + 1] = max(include, exclude);
            }
        }

        return dp[0][0]; // dp[0][-1+1]
    }
    // Appraoch-4 Tabluation + Space Optimisation
    int solveTabulationSpaceOtp(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // include
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev])
                {
                    include = 1 + nextRow[curr + 1]; // +1 discussed in tablation
                }
                // exclude
                int exclude = 0 + nextRow[prev + 1]; // +1 discussed in tablation

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }

        return nextRow[0]; // dp[0][-1+1]
    }
    // Approach-5 Time-Optimal Using Binary Search Logic
    int spaceOptimal(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                // lower_bound(ans.begin(),ans.end(),nums[i]) will return an address
                // after subtracting ans.begin() from above will get the final lower_bound index
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }
    int lengthOfLIS(vector<int> &nums)
    {
        // Approach-1
        return solve(nums, 0, -1);

        // Approach-2
        // row of n size because curr is going from 0 to n-1 where is nums.size()
        // col of n+1 size because prev is going from -1 to n-1 which is equal to nums.size()
        // therefore we require an extra index for -1
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return solveMemo(nums, 0, -1, dp);

        // Approach-3
        return solveTabulation(nums);

        // Approach-4
        return solveTabulationSpaceOtp(nums);

        // Approach-5
        return spaceOptimal(nums);
    }
};
