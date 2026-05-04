#define MOD 1000000007
#include <vector>
#include <iostream>
using namespace std;

// reccurive + memoization
long long int solve(int n, vector<long long int> &dp) {

    if (n == 1) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = ((n-1) % MOD * 
        ((solve(n-1, dp) % MOD + solve(n-2, dp) % MOD) % MOD)) % MOD;
    
    return dp[n];
}

// tabulation
long long int solve_tab(int n) {

    vector<int> dp(n+1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {

        long int first = dp[i-1] % MOD;
        long int second = dp[i-2] % MOD;
        long long int sum = (first + second) % MOD;

        dp[i] = ((i - 1) * sum ) % MOD;
    }

    return dp[n];
}

// space optimised
long long int solve_space_optimisied(int n) {

    long long int prev2 = 0;
    long long int prev1 = 1;

    for (int i = 3; i <= n; i++) {

        long int first = prev1 % MOD;
        long int second = prev2 % MOD;
        long long int sum = (first + second) % MOD;

        int ans = ((i - 1) * sum ) % MOD;

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int countDerangements(int n) {
    
    // reccursion + memoization
    // vector<long long int> dp(n+1, -1);

    // long long int ans = solve(n, dp);
    // return ans;

    // tabularisation
    // return solve_tab(n);

    // space optimisation
    return solve_space_optimisied(n);
}

// reccursive
// long long int countDerangements(int n) {
    
//     if (n == 1) {
//         return 0;
//     }

//     if (n == 2) {
//         return 1;
//     }

//     int ans = ((n-1) % MOD) * ((countDerangements(n-1) % MOD) 
//                         + (countDerangements(n-2) % MOD) % MOD);
    
//     return ans;
// }

// Focus on element 1.
    //It cannot stay at position 1, so it has (n - 1) choices.
    /*
        1 goes to position k
        Now we analyze two cases:
        Case 1: k-th element goes to position 1

            ?? Swap happens between 1 and k

            Now:

            Both positions are fixed
            Remaining (n-2) elements need derangement

            So contribution:

            ?? Case 2: k-th element does NOT go to position 1

        ?? No swap, more complex arrangement

        Now:

        We still have (n-1) elements to arrange
        But with restriction ? no one stays in original place

        So contribution:
        D(n)=(n?1)?(D(n?1)+D(n?2))
    */