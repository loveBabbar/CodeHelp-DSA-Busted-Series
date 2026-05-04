// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool cmp(pair<double, pair<int,int>> a, pair<double, pair<int,int>> b) {
        return a.first > b.first; // sort descending by value/weight
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        vector<pair<double, pair<int,int>>> items;

        // Step 1: store (value/weight, {value, weight})
        for(int i = 0; i < n; i++) {
            double ratio = (1.0 * val[i]) / wt[i];
            items.push_back({ratio, {val[i], wt[i]}});
        }

        // Step 2: sort by ratio descending
        sort(items.begin(), items.end(), cmp);

        double totalValue = 0.0;

        // Step 3: pick items greedily
        for(int i = 0; i < n; i++) {

            int value = items[i].second.first; // val
            int weight = items[i].second.second; // weight

            if(weight <= capacity) {
                totalValue += value;
                capacity -= weight;
            }
            else {
                // fraction
                
                double ratio = items[i].first;
                totalValue += capacity * ratio;
                break;
            }
        }

        return totalValue;
    }
};