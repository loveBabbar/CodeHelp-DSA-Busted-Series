#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int reccursion(vector<int> &v, int i, int j) {

        // first and last point are consecutive: no triangle possible
        if (i+1 == j) {
            return 0;
        }

        int min_score = INT_MAX;

        // take a point k from i+1 to <j in the polygon, and calculate score for all values of k. store minimum only
        for (int k = i+1; k < j; k++) {
            min_score = min(
                min_score, 
                v[i]*v[j]*v[k] + reccursion(v, i, k) + reccursion(v, k, j)
            );
        }
        return min_score;
    }

    int memoization(vector<int> &v, int i, int j, vector<vector<int>> &dp) {

        if (i+1 == j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int min_score = INT_MAX;
        for (int k = i+1; k < j; k++) {
            min_score = min(
                min_score, 
                v[i]*v[j]*v[k] + memoization(v, i, k, dp) + memoization(v, k, j, dp)
            );
        }
        return dp[i][j] = min_score;
    }

    int tabulation(vector<int> &v) {

        int n = v.size();
        vector<vector<int> > dp(n, vector<int> (n, 0));

        // **dp already filled with 0, so no need of base case**

        for (int i = n-1; i >= 0; i--) {

            for (int j = i+2; j < n; j++) {

                int min_score = INT_MAX;
                for (int k = i+1; k < j; k++) {
                    min_score = min(
                        min_score, 
                        v[i]*v[j]*v[k] + 
                        dp[i][k] + dp[k][j]
                    );
                }
                dp[i][j] = min_score;
            }
        }
        return dp[0][n-1];
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        
        // int n = values.size();
        // return reccursion(values, 0, n-1);

        // int n = values.size();
        // vector<vector<int> > dp(n, vector<int> (n, -1));
        // return memoization(values, 0, n-1, dp);

        return tabulation(values);
    }
};