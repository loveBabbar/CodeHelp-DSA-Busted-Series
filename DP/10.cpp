/*
@ Combination Sum

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

*/

// LINK : https://leetcode.com/problems/combination-sum/description/

// SPACE OPTIMISATION IS POSSIBLE BUT WILL DO LATER ON ... FOR THIS QUESITON

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solveIncExc(int index, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &temp)
    {

        if (index == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        // include kar lo if possible
        if (candidates[index] <= target)
        {
            temp.push_back(candidates[index]);
            // index + 1 nhi kara because may be next time again target-candidates[index] >= 0 toh     again wahi element temp mein push hoga
            solveIncExc(index, target - candidates[index], candidates, ans, temp);
            temp.pop_back();
        }

        // exclude wala case handle kar lo
        solveIncExc(index + 1, target, candidates, ans, temp);
    }
    // moving toward another approach which is include & exclude technique
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solveIncExc(0, target, candidates, ans, temp);
        return ans;
    }
};

/*
SAME QUESTION IN CODING NINJAS BUT IN A BIT DIFFERENT MANNER
CODE LINK :  https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252
here we are considering [1,2,3,4] [4,3,2,1] as differnet that's why we are not appling including and exlusion logic
Approach-1 Using Normal Recursion
*/
int solve(vector<int> &nums, int target)
{
    if (target < 0)
        return 0;

    if (target == 0)
        return 1;

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans += solve(nums, target - nums[i]);
    }

    return ans;
}

int findWays(vector<int> &num, int tar)
{
    return solve(nums, tar);
}