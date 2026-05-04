#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min_value = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {

            int profit = prices[i] - min_value;
            max_profit = max(profit, max_profit);
            min_value = min(min_value, prices[i]);
        }
        return max_profit;
    }
};