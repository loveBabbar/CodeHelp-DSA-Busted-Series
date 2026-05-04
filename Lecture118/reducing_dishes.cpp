#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int reccursion(vector<int>& satisfaction, int index, int time) {

        /*
            [4,3,2]
        */
        if (index == satisfaction.size()) {
            return 0;
        }

        int include = satisfaction[index] * (time+1) + reccursion(satisfaction, index+1, time+1);
        int exclude = 0 + reccursion(satisfaction, index+1, time);

        return max(include, exclude);
    }

    int memoization(vector<int>& satisfaction, int index, int time, vector<vector<int>> &dp) {

        if (index == satisfaction.size()) {
            return 0;
        }

        if (dp[index][time] != -1) {
            return dp[index][time];
        }

        int include = satisfaction[index] * (time+1) + 
                      memoization(satisfaction, index+1, time+1, dp);

        int exclude = 0 + memoization(satisfaction, index+1, time, dp);

        return dp[index][time] = max(include, exclude);
    }

    int tabulation(vector<int>& satisfaction) {

        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        // *** base case: element with [index] == 0th row, == 0, -> already satisfied

        for (int i = n-1; i >= 0; i--) {

            for (int time = i; time >= 0; time--) {

                int include = satisfaction[i] * (time+1) + 
                      dp[i+1][time+1];

                int exclude = 0 + dp[i+1][time];

                dp[i][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int space_optimised(vector<int>& satisfaction) {

        int n = satisfaction.size();

        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        // *** base case: element with [index] == 0th row, == 0, -> already satisfied

        for (int i = n-1; i >= 0; i--) {

            for (int time = i; time >= 0; time--) {

                int include = satisfaction[i] * (time+1) + 
                      next[time+1];

                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int start_index = 0, start_time = 0;
        sort(satisfaction.begin(), satisfaction.end());

        // return reccursion(satisfaction, start_index, start_time);

        vector<vector<int>> dp(satisfaction.size(), vector<int> (satisfaction.size(), -1));
        // return memoization(satisfaction, start_index, start_time, dp);

        // return tabulation(satisfaction);

        return space_optimised(satisfaction);
    }
};