// https://leetcode.com/problems/longest-palindromic-subsequence/submissions/1967786178

#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int recursion(string& a, string& b, int i, int j) {

        if (i == a.length() || j == b.length()) return 0;

        if (a[i] == b[j]) {
            // cout << i << " " << j << endl;
            return 1 + recursion(a, b, i+1, j+1);
        }
        else {
            // cout << i << "->" << j << endl;
            return max(recursion(a, b, i+1, j), recursion(a, b, i, j+1));
        }
    }

    int memoization(string& a, string& b, int i, int j, vector<vector<int>> &dp) {

        if (i == a.length() || j == b.length()) return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (a[i] == b[j]) {
            // cout << i << " " << j << endl;
            return dp[i][j] = 1 + memoization(a, b, i+1, j+1, dp);
        }
        else {
            // cout << i << "->" << j << endl;
            return dp[i][j] = max(memoization(a, b, i+1, j, dp), memoization(a, b, i, j+1, dp));
        }
    }

    int tabulation(string& a, string& b) {

        vector<vector<int>> dp(a.length()+1, vector<int> (b.length()+1, 0));

        for (int i = a.length()-1; i >= 0; i--) {

            for (int j = b.length()-1; j >= 0; j--) {

                if (a[i] == b[j]) {
                    // cout << i << " " << j << endl;
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else {
                    // cout << i << "->" << j << endl;
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }

    int space_optimisation(string& a, string& b) {

        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for (int i = a.length()-1; i >= 0; i--) {

            for (int j = b.length()-1; j >= 0; j--) {

                if (a[i] == b[j]) {
                    // cout << i << " " << j << endl;
                    curr[j] = 1 + next[j+1];
                }
                else {
                    // cout << i << "->" << j << endl;
                    curr[j] = max(next[j], curr[j+1]);
                }
            }
            next = curr;
        }
        return next[0];
    }
};


class Solution {
    MySolution sol;
public:
    int longestPalindromeSubseq(string s) {
        
        // pre-requisite: solve longest common subsequence (135)

        /* logic -
            1. reverse input string.
            2. find LCS in both string.
        */

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        return sol.space_optimisation(s, rev_s);
    }
};