#include <bits/stdc++.h>
using namespace std;

class MySolution {
private:
    int mem(int n, vector<int> &dp) {

        // n is number of nodes

        if (n <= 1) return 1;

        if (dp[n] != -1) return dp[n];

        int ans = 0;

        // explore all nodes from 1 to n as a root
        for (int i = 1; i <= n; i++) {

            // go to left and right of root i.e i and find all possible pairs for this root, 
            // add it in answer
            ans += mem(i-1, dp) * mem(n-i, dp);
        }
        return dp[n] = ans;
    }
public:
    int recursion(int n) {

        if (n <= 1) return 1;

        int ans = 0;

        // explore all nodes from 1 to n as a root
        for (int i = 1; i <= n; i++) {

            // go to left and right of root i.e i and find all possible pairs for this root, 
            // add it in answer
            ans += recursion(i-1) * recursion(n-i);
        }
        return ans;
    }

    int memoization(int n) {

        vector<int> dp(n+1, -1);
        return mem(n, dp);
    }

    // catalan number
    int tabulation(int n) {
        /*TC: O(n**2)
          SC: O(n)
        */

        vector<int> dp(n+1, 0);

        // **base case**
        dp[0] = dp[1] = 1;

        // i : number of nodes
        for (int i = 2; i <= n; i++) {

            // j : root node
            int ans = 0;
            for (int j = 1; j <= i; j++) {

                ans += dp[j-1] * dp[i-j];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};

class Solution {
private:
    MySolution solution;
public:
    int numTrees(int n) {
        
        // return solution.recursion(n);

        // return solution.memoization(n);

        return solution.tabulation(n);
    }
};