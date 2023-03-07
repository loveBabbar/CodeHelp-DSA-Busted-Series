/*
@ House Robber
NOTE : House can be in one line or it can be in a circular . This soultion is for circular
In case of one line simply apply logic of last question. Nothing more than that.
*/

// CODE LINK : https://leetcode.com/problems/house-robber/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solveTabulationSpaceOpt(vector<int> &nums)
    {
        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            int include = prev2 + nums[i];
            int exclude = prev1 + 0;

            int curr = max(include, exclude);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int> &nums)
    {

        vector<int> excludeLastHouse, includeLastHouse;

        // step-1
        excludeLastHouse.push_back(nums[0]);
        for (int i = 1; i < nums.size() - 1; i++)
        {
            excludeLastHouse.push_back(nums[i]);
            includeLastHouse.push_back(nums[i]);
        }
        includeLastHouse.push_back(nums[nums.size() - 1]);

        // step-2
        int excludedAns = solveTabulationSpaceOpt(excludeLastHouse);
        int includedAns = solveTabulationSpaceOpt(includeLastHouse);

        return max(excludedAns, includedAns);
    }
};