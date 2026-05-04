// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/1967708155

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int space_optimisation(vector<int> &prices, int fee) {

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
                    
                    int sell = +prices[index] + next[1] - fee;
                    int ignore = next[0];

                    profit = max(sell, ignore);
                }
                curr[can_buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        return space_optimisation(prices, fee);
    }
};