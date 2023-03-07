/*
@ Minimum Cost For Tickets

You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.

*/

// CODE LINK : https://leetcode.com/problems/minimum-cost-for-tickets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(vector<int> &days, vector<int> &costs, int index)
    {
        if (index >= days.size())
            return 0;

        int i;

        // 1 day pass
        int pass_1 = costs[0] + solve(days, costs, index + 1);

        // 7 day pass
        for (i = index; i < days.size() && days[i] < days[index] + 7; i++)
            ;
        int pass_7 = costs[1] + solve(days, costs, i);

        // 30 day pass
        for (i = index; i < days.size() && days[i] < days[index] + 30; i++)
            ;
        int pass_30 = costs[2] + solve(days, costs, i);

        return min(pass_1, min(pass_7, pass_30));
    }
    // Approach-2 Using Recursion + Memoisation
    int solveMemo(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
    {
        // step-1
        if (index >= days.size())
            return 0;

        // step-3
        if (dp[index] != -1)
            return dp[index];

        // step-2
        int i;

        // 1 day pass
        int pass_1 = costs[0] + solveMemo(days, costs, index + 1, dp);

        // 7 day pass
        for (i = index; i < days.size() && days[i] < days[index] + 7; i++)
            ;
        int pass_7 = costs[1] + solveMemo(days, costs, i, dp);

        // 30 day pass
        for (i = index; i < days.size() && days[i] < days[index] + 30; i++)
            ;
        int pass_30 = costs[2] + solveMemo(days, costs, i, dp);

        dp[index] = min(pass_1, min(pass_7, pass_30));

        return dp[index];
    }
    // Approach-3 Using Tabulation Method Bottom Up Approach with Right to Left
    int solveTabulation(vector<int> &days, vector<int> &costs)
    {
        // step-1 creation of dp array
        vector<int> dp(days.size() + 1, INT_MAX);
        dp[days.size()] = 0;

        // step-2
        for (int k = days.size() - 1; k >= 0; k--)
        {
            int i;

            // 1 day pass
            int pass_1 = costs[0] + dp[k + 1];

            // 7 day pass
            for (i = k; i < days.size() && days[i] < days[k] + 7; i++)
                ;
            int pass_7 = costs[1] + dp[i];

            // 30 day pass
            for (i = k; i < days.size() && days[i] < days[k] + 30; i++)
                ;
            int pass_30 = costs[2] + dp[i];

            dp[k] = min(pass_1, min(pass_7, pass_30));
        }

        return dp[0];
    }
    // Approach-4 Using Slicing Window + Queue for space optimisation
    int solveSliceWindow(vector<int> &days, vector<int> &costs)
    {

        int ans = 0;

        queue<pair<int, int>> month;
        queue<pair<int, int>> week;

        for (int day : days)
        {
            // step-1 remove expired days from queue
            while (!week.empty() && week.front().first + 7 <= day)
                week.pop();
            while (!month.empty() && month.front().first + 30 <= day)
                month.pop();

            // step-2 push curr day to queue
            week.push(make_pair(day, ans + costs[1]));
            month.push(make_pair(day, ans + costs[2]));

            // step-3 update answer
            ans = min(ans + costs[0], min(week.front().second, month.front().second));
        }

        return ans;
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        // Approach-1
        return solve(days, costs, 0);

        // Approach-2
        vector<int> dp(days.size() + 1, -1);
        return solveMemo(days, costs, 0, dp);

        // Approach-3
        return solveTabulation(days, costs);

        // Approach-4
        return solveSliceWindow(days, costs);
    }
};