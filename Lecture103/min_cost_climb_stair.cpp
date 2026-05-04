// https://leetcode.com/problems/min-cost-climbing-stairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    // without DP
    int get_min_cost(vector<int> &cost, int stair) {

        if (stair == 0) return cost[0];

        if (stair == 1) return cost[1];

        int min_cost = (min(get_min_cost(cost, stair-1), 
                            get_min_cost(cost, stair-2)) + cost[stair]);
        return min_cost;
    }

    // with DP
    int get_min_cost(vector<int> &cost, int stair, vector<int> &dp) {

        if (stair == 0) return cost[0];

        if (stair == 1) return cost[1];

        if (dp[stair] != -1) return dp[stair];

        return dp[stair] = (min(get_min_cost(cost, stair-1, dp), 
                            get_min_cost(cost, stair-2, dp)) + cost[stair]);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int total_stairs = cost.size();

        vector<int> dp(total_stairs+1, -1);

        int min_cost_to_climb = min(get_min_cost(cost, total_stairs-1, dp), 
                                    get_min_cost(cost, total_stairs-2, dp));

        return min_cost_to_climb;
    }
};