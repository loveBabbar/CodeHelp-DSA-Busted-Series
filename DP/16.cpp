/*
@ Minimum Sideway Jumps
Input: obstacles = [0,1,2,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).

Input: obstacles = [0,1,1,3,3,0]
Output: 0
Explanation: There are no obstacles on lane 2. No side jumps are required.

*/

// CODE LINK : https://leetcode.com/problems/minimum-sideway-jumps/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(vector<int> &obstacles, int currLane, int currPos)
    {
        // base case means reached destination
        if (currPos == obstacles.size() - 1)
        {
            return 0;
        }

        // Condition represents same-lane mein aage wali postion par obstacle nhi hain therefore aage badho!
        // obstacles[currPos+1] i.e, currPos=1 , then obstacles[1+1] means where is obstacle at 2nd position.
        // obstacles[currPos + 1] != currLane , represent obstacle at 2nd position is not in same-lane.
        if (obstacles[currPos + 1] != currLane)
        {
            return solve(obstacles, currLane, currPos + 1);
        }
        else
        {
            // INT_MAX because in case we are in middle 2nd lane & can jump on both side.
            // there we want to find minmum of 1st & 3rd recursive calls
            int ans = INT_MAX;
            // now we have to jump either on 1st , 2nd or 3rd lane . therefore loop-range = (i=1 ; i<=3)
            for (int i = 1; i <= 3; i++)
            {
                // currlane != i. Condition Represent we're not trying to jump on same-lane
                // obstacles[currPos] != i. Condition Represent if we are trying to jump in diff-lane then
                // shouldn't be any obstacles i.e, currPos=2 & i=3[trying to jump in 3rd lane]
                // obstacles[currPos] = obstacles[2nd Position] should not be at i which is 3rd lane.
                if (currLane != i && obstacles[currPos] != i)
                {
                    ans = min(ans, 1 + solve(obstacles, i, currPos));
                }
            }
            return ans;
        }
    }
    // Approach-2 Using Recursion + Memoisation Using DP Array
    int solveMemo(vector<int> &obstacles, int currLane, int currPos, vector<vector<int>> &dp)
    {
        // base-condition
        if (currPos == obstacles.size() - 1)
        {
            return 0;
        }
        // if answer present if dp array return from there only.
        if (dp[currLane][currPos] != -1)
        {
            return dp[currLane][currPos];
        }

        if (obstacles[currPos + 1] != currLane)
        {
            return solveMemo(obstacles, currLane, currPos + 1, dp);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (currLane != i && obstacles[currPos] != i)
                {
                    ans = min(ans, 1 + solveMemo(obstacles, i, currPos, dp));
                }
            }
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }
    // Approch-3 Using Bottom-up Tabulation Method
    int solveTabulation(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;
        // step-1 creation of dp array
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (obstacles[currPos + 1] != currLane)
                {
                    dp[currLane][currPos] = dp[currLane][currPos + 1];
                }
                else
                {
                    // sideway jumps
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (currLane != i && obstacles[currPos] != i)
                        {
                            ans = min(ans, 1 + dp[i][currPos + 1]); // why currPos+1 here very imp look in notebook.
                        }
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }
    // Approch-4 Using Bottom-up Tabulation Method + Space Optimisation
    int solveTabulationSpactOpt(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;
        // step-1 creation of dp array
        vector<int> curr(4, 1e9);
        vector<int> next(4, 1e9);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (obstacles[currPos + 1] != currLane)
                {
                    curr[currLane] = next[currLane];
                }
                else
                {
                    // sideway jumps
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (currLane != i && obstacles[currPos] != i)
                        {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1 + next[1], 1 + next[3]));
    }
    int minSideJumps(vector<int> &obstacles)
    {
        // Approach-1
        return solve(obstacles, 2, 0);

        // Approach-2
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        return solveMemo(obstacles, 2, 0, dp);

        // Approach-3
        return solveTabulation(obstacles);

        // Approach-4
        return solveTabulationSpactOpt(obstacles);
    }
};