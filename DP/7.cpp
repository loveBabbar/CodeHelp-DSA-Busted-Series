/*
@ Count derangements
i.e Something Like Permutations no. way i can be placed within array
so that it can placed anywhere within array except it's current position.
*/

// CODE LINK : https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#include <vector>
#define MOD 1000000007

// Approach-1 Using Normal Recursion
long long int solve(int n)
{
    // base-case
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    int ans = ((n - 1) % MOD * (solve(n - 1) % MOD + solve(n - 2) % MOD)) % MOD;

    return ans;
}

// Approach-2 Using Recursion + Memoisation
long long int solveMemo(int n, vector<long long int> &dp)
{
    // base-case
    if (n == 0)
        return 1;

    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (((n - 1) % MOD) * ((solveMemo(n - 1, dp) % MOD) + (solveMemo(n - 2, dp) % MOD)) % MOD);

    return dp[n];
}

// Approach-3 Using Tabulation Method
long long int solveTabulation(int n)
{

    vector<long long int> dp(n + 1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;

        long long int ans = ((i - 1) * sum) % MOD;

        dp[i] = ans;
    }

    return dp[n];
}

// Approach-4 Appliying Space Optimisation
long long int solveTabulationSpaceOtp(int n)
{

    // {null[0th-index] , prev2[1-position] , prev1[2-position] , n }

    long long int prev2 = 0; // [n == 1 i.e, means there is no means zero derangements]
    long long int prev1 = 1; // [n == 2 i.e, means there is only one derangements]

    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int sum = (first + second) % MOD;

        long long int ans = ((i - 1) * sum) % MOD;

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int countDerangements(int n)
{

    // Approach-1
    return solve(n);

    // Approach-2
    vector<long long int> dp(n + 1, -1);
    return solveMemo(n, dp);

    // Approach-3
    return solveTabulation(n);

    // Approach-4
    return solveTabulationSpaceOtp(n);
}