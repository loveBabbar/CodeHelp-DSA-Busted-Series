// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/1967414749

#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int recursion(int index, bool can_buy, vector<int> &prices, int limit) {

        if (index == prices.size()) return 0;

        if (limit == 0) return 0;

        int profit = 0;
        if (can_buy) {

            int buy = -prices[index] + recursion(index+1, false, prices, limit);
            int ignore = recursion(index+1, true, prices, limit);

            profit = max(buy, ignore);
        }
        else {
            
            // buy and selled -> limit - 1
            int sell = +prices[index] + recursion(index+1, true, prices, limit-1);
            int ignore = recursion(index+1, false, prices, limit);

            profit = max(sell, ignore);
        }
        return profit;
    }

    int memoization(int index, bool can_buy, vector<int> &prices, vector<vector<vector<int>>> &dp,
        int limit) {

        if (index == prices.size()) return 0;

        if (limit == 0) return 0;

        if (dp[index][can_buy][limit] != -1) return dp[index][can_buy][limit];

        int profit = 0;
        if (can_buy) {

            int buy = -prices[index] + memoization(index+1, false, prices, dp, limit);
            int ignore = memoization(index+1, true, prices, dp, limit);

            profit = max(buy, ignore);
        }
        else {
            
            int sell = +prices[index] + memoization(index+1, true, prices, dp, limit-1);
            int ignore = memoization(index+1, false, prices, dp, limit);

            profit = max(sell, ignore);
        }
        return dp[index][can_buy][limit] = profit;
    }

    int tabulation(vector<int> &prices) {

        int n = prices.size();
        vector <vector <vector<int> > > dp(n+1, vector<vector<int>>(2, vector<int> (3, 0)));

        for (int index = n-1; index >= 0; index--) {

            for (int can_buy = 0; can_buy <= 1; can_buy++) {

                for (int limit = 1; limit <= 2; limit++) {
                    
                    int profit = 0;
                    if (can_buy) {

                        int buy = -prices[index] + dp[index+1][0][limit];
                        int ignore = dp[index+1][1][limit];

                        profit = max(buy, ignore);
                    }
                    else {
                        
                        int sell = +prices[index] + dp[index+1][1][limit-1];
                        int ignore = dp[index+1][0][limit];

                        profit = max(sell, ignore);
                    }
                    dp[index][can_buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int space_optimisation(vector<int> &prices) {

        int n = prices.size();

        vector<vector<int>> curr(2, vector<int> (3, 0));
        vector<vector<int>> next(2, vector<int> (3, 0));

        for (int index = n-1; index >= 0; index--) {

            for (int can_buy = 0; can_buy <= 1; can_buy++) {

                for (int limit = 1; limit <= 2; limit++) {
                    
                    int profit = 0;
                    if (can_buy) {

                        int buy = -prices[index] + next[0][limit];
                        int ignore = next[1][limit];

                        profit = max(buy, ignore);
                    }
                    else {
                        
                        int sell = +prices[index] + next[1][limit-1];
                        int ignore = next[0][limit];

                        profit = max(sell, ignore);
                    }
                    curr[can_buy][limit] = profit;
                }
                next = curr;
            }
        }
        return next[1][2];
    }
};


class Solution {
private:
    MySolution sol;
public:
    int maxProfit(vector<int>& prices) {

        // pre-requites: 121, 122
        
        // return sol.recursion(0, true, prices, 2);

        vector <vector <vector<int> > > dp(prices.size(), vector<vector<int>>(2, vector<int> (3, -1)));
        // return sol.memoization(0, true, prices, dp, 2);

        // return sol.tabulation(prices);

        return sol.space_optimisation(prices);
    }
};