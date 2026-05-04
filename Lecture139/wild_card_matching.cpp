// https://leetcode.com/problems/wildcard-matching/submissions/1968239526

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool recursion(string& s, string& p, int i, int j) {

        // ------Base Cases------

        // 1. both strings matches
        if (i < 0 && j < 0) {
            return true;
        }

        //2. pattern is no more but string is
        if (i >=0 && j < 0) {
            return false;
        }

        // 3. string is no more but pattern is. (this contains two cases)
        if (i < 0 && j >= 0) {

            for (int k = 0; k <= j; k++) {

                // 3.1 - if remaing char in pattern contains any other char than '*'
                if (p[k] != '*') {
                    return false;
                }
            }

            // 3.2 - if all remaing chars was '*'
            return true;
        }
        // ---------------------------------

        // matches
        if (s[i] == p[j] || p[j] == '?') {

            // move in both strings
            return recursion(s, p, i-1, j-1);
        }
        else if (p[j] == '*') {

            // replace '*' with '' empty string
            // replace '*' with '*s[i]'
            return (recursion(s, p, i-1, j) ||
                recursion(s, p, i, j-1)
            );
        }
        else {
            // charecter not matching
            return false;
        }
    }

/*
    // 0 based indexing
    bool memoization(string& s, string& p, int i, int j, vector<vector<int>> &dp) {

        // ------Base Cases------

        // 1. both strings matches
        if (i < 0 && j < 0) {
            return true;
        }

        //2. pattern is no more but string is
        if (i >=0 && j < 0) {
            return false;
        }

        // 3. string is no more but pattern is. (this contains two cases)
        if (i < 0 && j >= 0) {

            for (int k = 0; k <= j; k++) {

                // 3.1 - if remaing char in pattern contains any other char than '*'
                if (p[k] != '*') {
                    return false;
                }
            }

            // 3.2 - if all remaing chars was '*'
            return true;
        }
        // ---------------------------------

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // matches
        if (s[i] == p[j] || p[j] == '?') {

            // move in both strings
            return dp[i][j] = memoization(s, p, i-1, j-1, dp);
        }
        else if (p[j] == '*') {

            // replace '*' with '' empty string
            // replace '*' with '*s[i]'
            return dp[i][j] = (memoization(s, p, i-1, j, dp) ||
                memoization(s, p, i, j-1, dp)
            );
        }
        else {
            // charecter not matching
            return dp[i][j] = false;
        }
    }
*/

    // 1 based indexing
    bool memoization(string& s, string& p, int i, int j, vector<vector<int>> &dp) {

        // ------Base Cases------

        // 1. both strings matches
        if (i == 0 && j == 0) {
            return true;
        }

        //2. pattern is no more but string is
        if (i > 0 && j == 0) {
            return false;
        }

        // 3. string is no more but pattern is. (this contains two cases)
        if (i == 0 && j > 0) {

            for (int k = 1; k <= j; k++) {

                // 3.1 - if remaing char in pattern contains any other char than '*'
                if (p[k-1] != '*') {
                    return false;
                }
            }

            // 3.2 - if all remaing chars was '*'
            return true;
        }
        // ---------------------------------

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // matches
        if (s[i-1] == p[j-1] || p[j-1] == '?') {

            // move in both strings
            return dp[i][j] = memoization(s, p, i-1, j-1, dp);
        }
        else if (p[j-1] == '*') {

            // replace '*' with '' empty string
            // replace '*' with '*s[i]'
            return dp[i][j] = (memoization(s, p, i-1, j, dp) ||
                memoization(s, p, i, j-1, dp)
            );
        }
        else {
            // charecter not matching
            return dp[i][j] = false;
        }
    }

    bool tabulation(string& s, string &p) {

        vector<vector<int>> dp(s.length()+1, vector<int> (p.length()+1, 0));

        // **base cases**
        dp[0][0] = true;

        for (int j = 1; j <= p.length(); j++) {

            bool flag = true;
            for (int k = 1; k <= j; k++) {

                if (p[k-1] != '*') {
                    flag =  false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        // ----------------------

        for (int i = 1; i <= s.length(); i++) {

            for (int j = 1; j <= p.length(); j++) {

                if (s[i-1] == p[j-1] || p[j-1] == '?') {

                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {

                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }

    bool space_optimisation(string& s, string &p) {

        vector<int> curr(p.length()+1, 0);
        vector<int> prev(p.length()+1, 0);

        // **base cases**
        prev[0] = true;

        for (int j = 1; j <= p.length(); j++) {

            bool flag = true;
            for (int k = 1; k <= j; k++) {

                if (p[k-1] != '*') {
                    flag =  false;
                    break;
                }
            }
            prev[j] = flag;
        }
        // ----------------------

        for (int i = 1; i <= s.length(); i++) {

            for (int j = 1; j <= p.length(); j++) {

                if (s[i-1] == p[j-1] || p[j-1] == '?') {

                    curr[j] = prev[j-1];
                }
                else if (p[j-1] == '*') {

                    curr[j] = (prev[j] || curr[j-1]);
                }
                else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[p.length()];
    }

public:
    bool isMatch(string s, string p) {
        
        // return recursion(s, p, s.length()-1, p.length()-1);

        vector<vector<int>> dp(s.length()+1, vector<int> (p.length()+1, -1));
        // return memoization(s, p, s.length(), p.length(), dp);

        // return tabulation(s, p);

        return space_optimisation(s, p);
    }
};