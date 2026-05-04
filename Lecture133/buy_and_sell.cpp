// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/1967437149

// **important question**

#include <bits/stdc++.h>
using namespace std;

class MySolution {
    // using 3D DP
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

    int tabulation(vector<int> &prices, int k) {

        int n = prices.size();
        vector <vector <vector<int> > > dp(n+1, vector<vector<int>>(2, vector<int> (k+1, 0)));

        for (int index = n-1; index >= 0; index--) {

            for (int can_buy = 0; can_buy <= 1; can_buy++) {

                for (int limit = 1; limit <= k; limit++) {
                    
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
        return dp[0][1][k];
    }

    int space_optimisation(vector<int> &prices, int k) {

        int n = prices.size();

        vector<vector<int>> curr(2, vector<int> (k+1, 0));
        vector<vector<int>> next(2, vector<int> (k+1, 0));

        for (int index = n-1; index >= 0; index--) {

            for (int can_buy = 0; can_buy <= 1; can_buy++) {

                for (int limit = 1; limit <= k; limit++) {
                    
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
        return next[1][k];
    }
};

class OperationNo {
    // using 2D DP
public:
    int recursion(int index, int operation_no, int k, vector<int> &prices) {

        if (index == prices.size()) return 0;

        if (operation_no == 2 * k) return 0;

        int profit = 0;
        if (operation_no % 2 == 0) {

            int buy = -prices[index] + recursion(index+1, operation_no+1, k, prices);
            int ignore = recursion(index+1, operation_no, k, prices);
            profit = max(buy, ignore);
        }
        else {

            int sell = +prices[index] + recursion(index+1, operation_no+1, k, prices);
            int ignore = recursion(index+1, operation_no, k, prices);

            profit = max(sell, ignore);
        }
        return profit;
    }

    int memoization(int index, int operation_no, int k, vector<int> &prices, vector<vector<int>> &dp) {

        if (index == prices.size()) return 0;

        if (operation_no == 2 * k) return 0;

        if (dp[index][operation_no] != -1) return dp[index][operation_no];

        int profit = 0;
        if (operation_no % 2 == 0) {

            int buy = -prices[index] + memoization(index+1, operation_no+1, k, prices, dp);
            int ignore = memoization(index+1, operation_no, k, prices, dp);
            profit = max(buy, ignore);
        }
        else {

            int sell = +prices[index] + memoization(index+1, operation_no+1, k, prices, dp);
            int ignore = memoization(index+1, operation_no, k, prices, dp);

            profit = max(sell, ignore);
        }
        return dp[index][operation_no] = profit;
    }

    int tabulation(int k, vector<int> &prices) {

        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2*k + 1, 0));

        for (int index = n-1; index >= 0; index--) {

            for (int operation_no = 0; operation_no < 2*k; operation_no++) {

                int profit = 0;
                if (operation_no % 2 == 0) {

                    int buy = -prices[index] + dp[index+1][operation_no+1];
                    int ignore = dp[index+1][operation_no];
                    profit = max(buy, ignore);
                }
                else {

                    int sell = +prices[index] + dp[index+1][operation_no+1];
                    int ignore = dp[index+1][operation_no];

                    profit = max(sell, ignore);
                }
                dp[index][operation_no] = profit;
            }
        }
        return dp[0][0];
    }

    int space_optimisation(int k, vector<int> &prices) {

        int n = prices.size();
         
        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);

        for (int index = n-1; index >= 0; index--) {

            for (int operation_no = 0; operation_no < 2*k; operation_no++) {

                int profit = 0;
                if (operation_no % 2 == 0) {

                    int buy = -prices[index] + next[operation_no+1];
                    int ignore = next[operation_no];
                    profit = max(buy, ignore);
                }
                else {

                    int sell = +prices[index] + next[operation_no+1];
                    int ignore = next[operation_no];

                    profit = max(sell, ignore);
                }
                curr[operation_no] = profit;
            }
            next = curr;
        }
        return next[0];
    }
};

class Solution {
    MySolution sol;
    OperationNo solution;
public:
    int maxProfit(int k, vector<int>& prices) {
        
        // return sol.recursion(0, true, prices, k);

        // vector <vector <vector<int> > > dp(prices.size(), vector<vector<int>>(2, vector<int> (k+1, -1)));
        // return sol.memoization(0, true, prices, dp, k);

        // return sol.tabulation(prices, k);

        // return sol.space_optimisation(prices, k);

        // ------operation number-------
        // return solution.recursion(0, k, 0, prices);

        vector<vector<int>> dp(prices.size(), vector<int> (2*k + 1, -1));
        // return solution.memoization(0, 0, k, prices, dp);

        // return solution.tabulation(k, prices);

        return solution.space_optimisation(k, prices);
    }
};