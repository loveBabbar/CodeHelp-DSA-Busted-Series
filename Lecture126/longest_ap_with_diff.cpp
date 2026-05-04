#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int, int> dp;

        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {

            int temp = arr[i] - difference;
            int temp_ans = 0;

            // ans already exits
            if (dp.count(temp)) {
                temp_ans = dp[temp];
            }

            // current answer update
            dp[arr[i]] = 1 + temp_ans;

            // answer update
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};