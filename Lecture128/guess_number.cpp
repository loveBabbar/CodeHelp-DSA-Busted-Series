// https://leetcode.com/problems/guess-number-higher-or-lower-ii/submissions/1966622701

#include <bits/stdc++.h>
using namespace std;

class Solution {

    int recursion(int start, int end) {

        if (start >= end) return 0;

        int maxi = INT_MAX;
        for (int i = start; i < end; i++) {

            maxi = min(maxi, i + max(recursion(start, i-1), recursion(i+1, end)));
        }
        return maxi;
    }

    int memoization(int start, int end, vector<vector<int>> &dp) {

        if (start >= end) return 0;

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int maxi = INT_MAX;
        for (int i = start; i < end; i++) {

            maxi = min(maxi, i + max(memoization(start, i-1, dp), memoization(i+1, end, dp)));
        }
        return dp[start][end] = maxi;
    }

    int tabulation(int n) {

        vector<vector<int> > dp(n+1, vector<int> (n+1, 0));

        for (int start = n; start >= 1; start--) {
            for (int end = start; end <= n; end++) {

                if (start == end) continue;
                
                int maxi = INT_MAX;
                for (int i = start; i < end; i++) {

                    maxi = min(maxi, i + max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = maxi;
            }
        }
        return dp[1][n];
    }
public:
    int getMoneyAmount(int n) {
        
        // return recursion(1, n);

        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        // return memoization(1, n, dp);

        return tabulation(n);
    }
};