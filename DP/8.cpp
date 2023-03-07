/*
@ Painting the Fence

Input:
N=3,  K=2
Output: 6

Input:
N=2,  K=4
Output: 16

*/

// CODE LINK : https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
// CODING NINJAS CODE LINK : https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?leftPanelTab=0

#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

class Solution
{
public:
    long long int mod = 1000000007;
    long long int add(int a, int b)
    {
        return ((a % mod) + (b % mod)) % mod;
    }
    long long int mul(int a, int b)
    {
        // In case test case fails use
        // ((a % mod) * 1LL * (b % mod)) % mod;
        return ((a % mod) * (b % mod)) % mod;
    }

    // Approach-1 Using Normal Recursion
    long long int solve(int n, int k)
    {
        // base-case
        if (n == 1)
            return k;

        if (n == 2)
            return add(k, mul(k, k - 1));

        return add(mul(solve(n - 2, k), k - 1), mul(solve(n - 1, k), k - 1));
    }

    // Approach-2 Using Recursion + Memoisation
    long long int solveMemo(int n, int k, vector<long long int> &dp)
    {
        // base-case
        if (n == 1)
            return k;

        if (n == 2)
            return add(k, mul(k, k - 1));

        if (dp[n] != -1)
            return dp[n];

        dp[n] = add(mul(solveMemo(n - 2, k, dp), k - 1), mul(solveMemo(n - 1, k, dp), k - 1));

        return dp[n];
    }

    // Approach-3 Using Tabulation Method -> Bottom Up Approach
    long long int solveUsingTab(int n, int k)
    {

        vector<long long int> dp(n + 1, 0);

        dp[1] = k;
        dp[2] = add(k, mul(k, k - 1));

        for (int i = 3; i <= n; i++)
        {
            dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
        }

        return dp[n];
    }

    // Approach-4 Space Optimisation Along with Tabulation
    long long int solveUsingTabSpaceOpt(int n, int k)
    {

        // {null[0th-index] , prev2[1-position] , prev1[2-position] , i }

        // base-case
        if (n == 1)
            return k;

        if (n == 2)
            return add(k, mul(k, k - 1));

        long long int prev2 = k;                     // n == 1
        long long int prev1 = add(k, mul(k, k - 1)); // n == 2

        for (int i = 3; i <= n; i++)
        {
            long long int ans = add(mul(prev2, k - 1), mul(prev1, k - 1));

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }
    long long countWays(int n, int k)
    {
        // Approach-1
        return solve(n, k);

        // Approach-2
        vector<long long int> dp(n + 1, -1);
        return solveMemo(n, k, dp);

        // Appraoch-3
        return solveUsingTab(n, k);

        // Appraoch-4
        return solveUsingTabSpaceOpt(n, k);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends