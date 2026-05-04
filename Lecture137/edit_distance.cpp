// https://leetcode.com/problems/edit-distance/submissions/1967969898

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursion(string &a, string &b, int i, int j) {

        // **base case**
        if (i == a.length()) {

            // remaing charter in second string -> add equicalent operation to dissolve them,
            // in simple word "b.length() - j" gives you the remaing chacter of second string when first is 
            // already completed
            return b.length() - j;
        }

        if (j == b.length()) {
            return a.length() - i;
        }

        int min_operation = 0;
        if (a[i] == b[j]) {
            return recursion(a, b, i+1, j+1);
        }
        else {

            // **explore all cases

            // insert charecter of second string
            // +1 b/c you are performing an operation here
            int insert_operation = 1 + recursion(a, b, i, j+1);

            int delete_operation = 1 + recursion(a, b, i+1, j);

            int replace_operation = 1 + recursion(a, b, i+1, j+1);

            // **explored all cases now return the casr with minimum operations required**
            min_operation = min(insert_operation, min(delete_operation, replace_operation));
        }
        return min_operation;
    }

    int memoization(string &a, string &b, int i, int j, vector<vector<int>> &dp) {

        // **base case**
        if (i == a.length()) {

            // remaing charter in second string -> add equicalent operation to dissolve them,
            // in simple word "b.length() - j" gives you the remaing chacter of second string when first is 
            // already completed
            return b.length() - j;
        }

        if (j == b.length()) {
            return a.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int min_operation = 0;
        if (a[i] == b[j]) {
            return dp[i][j] = memoization(a, b, i+1, j+1, dp);
        }
        else {

            // **explore all cases

            // insert charecter of second string
            // +1 b/c you are performing an operation here
            int insert_operation = 1 + memoization(a, b, i, j+1, dp);

            int delete_operation = 1 + memoization(a, b, i+1, j, dp);

            int replace_operation = 1 + memoization(a, b, i+1, j+1, dp);

            // **explored all cases now return the casr with minimum operations required**
            min_operation = min(insert_operation, min(delete_operation, replace_operation));
        }
        return dp[i][j] = min_operation;
    }

    int tabulation(string &a, string &b) {

        vector<vector<int>> dp(a.length()+1, vector<int> (b.length()+1, 0));

        // **base case**
        // can solve base case in O(n)
        for (int i = 0; i <= a.length(); i++) {
            for (int j = 0; j <= b.length(); j++) {

                if (i == a.length()) {
                    dp[i][j] = b.length() - j;
                }

                if (j == b.length()) {
                    dp[i][j] = a.length() - i;
                }
            }
        }

        // now run the loop by for loop instead of recursion
        for (int i = a.length()-1; i >= 0; i--) {
            for (int j = b.length()-1; j >= 0; j--) {
                
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i+1][j+1];
                }
                else {

                    int insert_operation = 1 + dp[i][j+1];

                    int delete_operation = 1 + dp[i+1][j];

                    int replace_operation = 1 + dp[i+1][j+1];

                    // **explored all cases now return the casr with minimum operations required**
                    dp[i][j] = min(insert_operation, min(delete_operation, replace_operation));
                }
            }
        }

        // return the same value passed in recursive solution
        return dp[0][0];
    }

    int space_optimised(string &a, string &b) {

        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        // **base case**
        for (int i = 0; i < b.length(); i++) {
            next[i] = b.length() - i;
        }
        
        // now run the loop by for loop instead of recursion
        for (int i = a.length()-1; i >= 0; i--) {
            for (int j = b.length()-1; j >= 0; j--) {

                // **catch** : obtained from base case
                curr[b.length()] = a.length() - i;
                
                if (a[i] == b[j]) {
                    curr[j] = next[j+1];
                }
                else {

                    int insert_operation = 1 + curr[j+1];

                    int delete_operation = 1 + next[j];

                    int replace_operation = 1 + next[j+1];

                    // **explored all cases now return the casr with minimum operations required**
                    curr[j] = min(insert_operation, min(delete_operation, replace_operation));
                }
            }
            next = curr;
        }

        // return the same value passed in recursive solution
        return next[0];
    }

public:
    int minDistance(string word1, string word2) {

        // **edge cases**
        if (word1.length() == 0) {
            return word2.length();
        }

        if (word2.length() == 0) {
            return word1.length();
        }

        // "same as LIS(logest common subsequence)"
        // return recursion(word1, word2, 0, 0);

        vector<vector<int>> dp(word1.length(), vector<int> (word2.length(), -1));
        // return memoization(word1, word2, 0, 0, dp);

        // return tabulation(word1, word2);

        return space_optimised(word1, word2);
    }
};