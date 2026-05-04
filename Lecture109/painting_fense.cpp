#include <bits/stdc++.h> 
using namespace std;

#define MOD 1000000007

int add(int a, int b) {
    return (a%MOD + b%MOD) % MOD;
}

int mul(int a, int b) {
    return ((a%MOD)*1LL * (b%MOD)) % MOD;
}

int reccursion(int n, int k) {

    if (n == 1) return k;

    if (n == 2) {
        return add(k, mul(k, (k-1)));
    }

    int same = mul(reccursion(n-2, k), k-1);
    // cout << same << endl;
    int diff = mul(reccursion(n-1, k), k-1);

    int total = add(same, diff);

    return total;
}

int memoization(int n, int k, vector<int> &dp) {
    
    if (n == 1) return k;

    if (n == 2) {
        return add(k, mul(k, (k-1)));
    }

    if (dp[n] != -1) return dp[n];

    int same = mul(memoization(n-2, k, dp), k-1);
    int diff = mul(memoization(n-1, k, dp), k-1);

    // cout << add(same, diff) << endl;

    return dp[n] = add(same, diff);
}

int tabulization(int n, int k) {

    vector<int> dp(n+1, -1);
    
    dp[1] = k;
    dp[2] = add(k, mul(k, (k-1)));

    for (int i = 3; i <= n; i++) {

        int same = mul(dp[i-2], k-1);
        int diff = mul(dp[i-1], k-1);

        dp[i] = add(same, diff);
    }

    return dp[n];
}

int space_optimised(int n, int k) {

    int prev2 = k;
    int prev1 = add(k, mul(k, (k-1)));

    for (int i = 3; i <= n; i++) {

        int same = mul(prev2, k-1);
        int diff = mul(prev1, k-1);

        int total = add(same, diff);

        prev2 = prev1;
        prev1 = total;
    }

    return prev1;
}

int numberOfWays(int n, int k) {

    // -------only reccursion -> exponential----------
    // return reccursion(n, k);

    // ---------reccursion + memoization -> liner----------
    // vector<int> dp(n+1, -1);
    // return memoization(n, k, dp);

    //-----------tabulization -> linear--------------
    // return tabulization(n, k);

    //-----------space optimisation -> linear--------------
    return space_optimised(n, k);
}
