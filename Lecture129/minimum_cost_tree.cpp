#include <bits/stdc++.h>
using namespace std;

int tabulation(vector<int>& arr) {
    int n = arr.size();

    //Step 1: Precompute max in range
    map<pair<int, int>, int> max_in_range;

    for (int i = 0; i < n; i++) {
        max_in_range[{i, i}] = arr[i];
        for (int j = i + 1; j < n; j++) {
            max_in_range[{i, j}] = max(arr[j], max_in_range[{i, j - 1}]);
        }
    }

    //Step 2: DP table
    vector<vector<int>> dp(n, vector<int>(n, 0));

    //Step 3: length loop
    for (int len = 2; len <= n; len++) {

        for (int left = 0; left <= n - len; left++) {

            int right = left + len - 1;
            dp[left][right] = INT_MAX;

            // Partition loop
            for (int i = left; i < right; i++) {

                int cost = max_in_range[{left, i}] * max_in_range[{i+1, right}]
                         + dp[left][i]
                         + dp[i+1][right];

                dp[left][right] = min(dp[left][right], cost);
            }
        }
    }

    return dp[0][n-1];
}


class Solution {
private:
    int recursion(vector<int>& arr, map<pair<int, int>, int> max_in_range, int left, int right) {

        // **leaf node**
        if (left == right) return 0;

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {

            ans = min(ans, max_in_range[{left, i}] * max_in_range[{i+1, right}] +
                recursion(arr, max_in_range, left, i) +
                recursion(arr, max_in_range, i+1, right)
            );
        }
        return ans;
    }

    int memoization(vector<int>& arr, map<pair<int, int>, int> max_in_range, int left, int right, 
        vector<vector<int>> &dp) {

        // **leaf node**
        if (left == right) return 0;

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {

            ans = min(ans, max_in_range[{left, i}] * max_in_range[{i+1, right}] +
                memoization(arr, max_in_range, left, i, dp) +
                memoization(arr, max_in_range, i+1, right, dp)
            );
        }
        return dp[left][right] = ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        map<pair<int, int>, int> max_in_range;

        // calculate the maximum value in all ranges
        for (int i = 0; i < arr.size(); i++) {

            max_in_range[{i, i}] = arr[i];
            for (int j = i+1; j < arr.size(); j++) {
                max_in_range[{i, j}] = max(arr[j], max_in_range[{i, j-1}]);
            }
        }

        // return recursion(arr, max_in_range, 0, arr.size()-1);

        vector<vector<int>> dp(arr.size(), vector<int> (arr.size(), -1));
        // return memoization(arr, max_in_range, 0, arr.size()-1, dp);

        return tabulation(arr);
    }
};