// https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        
        sort(prices.begin(), prices.end());
        
        int min_price = 0;
        int buy_index = 0;
        int free_index = prices.size()-1;
        
        while (buy_index <= free_index) {
            
            min_price = min_price + prices[buy_index];
            
            buy_index += 1;
            free_index = free_index - k;
        }
        
        int max_price = 0;
        buy_index = prices.size()-1;
        free_index = 0;
        
        while (buy_index >= free_index) {
            
            max_price = max_price + prices[buy_index];
            
            buy_index -= 1;
            free_index = free_index + k;
        }
        
        vector <int> ans;
        ans.push_back(min_price);
        ans.push_back(max_price);
        return ans;
        
    }
};