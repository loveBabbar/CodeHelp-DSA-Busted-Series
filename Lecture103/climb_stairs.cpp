#include <bits/stdc++.h> 
#define MOD 1000000007
using namespace std;

/*
// This I have solved on 'Day-9' from Lecture 32 (Understanding Reccursion)
int countDistinctWays(int nStairs) {
    //  Write your code here.

    if (nStairs < 0) return 0;

    if (nStairs == 0) return 1;

    int ans = countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);

    return ans;
}
*/


// Today is Day 69, Lecture 103 (DP)

/*
// Keep going bro, proud of you,,,

// first let's solve it by only reccursion -> TLE
int ways_to_climb(long long final_stair, int cur_stair) {

    if (cur_stair == final_stair) return 1;

    if (cur_stair > final_stair) return 0;

    return (ways_to_climb(final_stair, cur_stair+1) + ways_to_climb(final_stair, cur_stair+2)) % MOD;
}

int countDistinctWays(int nStairs) {

    int ways = ways_to_climb(nStairs, 0);

    return ways;
}
*/


// DP solution, I tried it my myself
int ways_to_climb(long long final_stair, int cur_stair, vector<int> &dp) {

    if (cur_stair == final_stair) return 1;

    if (cur_stair > final_stair) return 0;

    if (dp[cur_stair] != -1) {
        return dp[cur_stair];
    }

    return dp[cur_stair] = (ways_to_climb(final_stair, cur_stair+1, dp) + ways_to_climb(final_stair, cur_stair+2, dp)) % MOD;
}

int countDistinctWays(int nStairs) {

    vector<int> dp(nStairs, -1);

    int ways = ways_to_climb(nStairs, 0, dp);

    return ways;
}