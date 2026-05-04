#include <bits/stdc++.h>
using namespace std;

int reccursion(vector<int> &num, int tar) {

    if (tar < 0) return 0;

    // target achieved by one way
    if (tar == 0) return 1;

    int ans = 0;
    // *** call reccursion for all element of vector***
    for (int i = 0; i < num.size(); i++) {
        ans += reccursion(num, tar-num[i]);
    }

    return ans;
}

int memoization(vector<int> &num, int tar, vector<int> &dp) {

    if (tar < 0) return 0;

    // target achieved by one way
    if (tar == 0) return 1;

    if (dp[tar] != -1) return dp[tar];

    long long int ans = 0;
    // *** call reccursion for all element of vector***
    for (int i = 0; i < num.size(); i++) {
        ans += memoization(num, tar-num[i], dp);
    }

    return dp[tar] = ans;
}

int findWays(vector<int> &num, int tar)
{
    // ** reccursive way**
    // return reccursion(num, tar);

    vector<int> dp(tar+1, -1);
    return memoization(num, tar, dp);
}
