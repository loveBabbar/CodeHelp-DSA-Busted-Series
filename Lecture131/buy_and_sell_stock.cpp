// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/1967360598

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursion(int index, bool can_buy, vector<int> &prices) {

        if (index == prices.size()) return 0;

        int profit = 0;
        if (can_buy) {

            int buy = -prices[index] + recursion(index+1, false, prices);
            int ignore = recursion(index+1, true, prices);

            profit = max(buy, ignore);
        }
        else {
            
            int sell = +prices[index] + recursion(index+1, true, prices);
            int ignore = recursion(index+1, false, prices);

            profit = max(sell, ignore);
        }
        return profit;
    }

    int memoization(int index, bool can_buy, vector<int> &prices, vector<vector<int>> &dp) {

        if (index == prices.size()) return 0;

        if (dp[index][can_buy] != -1) return dp[index][can_buy];

        int profit = 0;
        if (can_buy) {

            int buy = -prices[index] + memoization(index+1, false, prices, dp);
            int ignore = memoization(index+1, true, prices, dp);

            profit = max(buy, ignore);
        }
        else {
            
            int sell = +prices[index] + memoization(index+1, true, prices, dp);
            int ignore = memoization(index+1, false, prices, dp);

            profit = max(sell, ignore);
        }
        return dp[index][can_buy] = profit;
    }

    int tabulation(vector<int> &prices) {

        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        for (int index = n-1; index >= 0; index--) {

            for (int can_buy = 0; can_buy <= 1; can_buy++) {

                int profit = 0;
                if (can_buy) {

                    int buy = -prices[index] + dp[index+1][0];
                    int ignore = dp[index+1][1];

                    profit = max(buy, ignore);
                }
                else {
                    
                    int sell = +prices[index] + dp[index+1][1];
                    int ignore = dp[index+1][0];

                    profit = max(sell, ignore);
                }
                dp[index][can_buy] = profit;
            }
        }
        return dp[0][1];
    }

    int space_optimisation(vector<int> &prices) {

        int n = prices.size();

        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n-1; index >= 0; index--) {

            for (int can_buy = 0; can_buy <= 1; can_buy++) {

                int profit = 0;
                if (can_buy) {

                    int buy = -prices[index] + next[0];
                    int ignore = next[1];

                    profit = max(buy, ignore);
                }
                else {
                    
                    int sell = +prices[index] + next[1];
                    int ignore = next[0];

                    profit = max(sell, ignore);
                }
                curr[can_buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        
        // return recursion(0, true, prices);

        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        // return memoization(0, true, prices, dp);

        // return tabulation(prices);

        return space_optimisation(prices);
    }
};