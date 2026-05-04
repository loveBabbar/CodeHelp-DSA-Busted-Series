#include <bits/stdc++.h> 
using namespace std;

// with reccursion only
int get_min_count(vector<int> &num, int target) {

    if (target == 0) return 0;

    if (target < 0) return INT_MAX;

    int min_count = INT_MAX;
    // run for all elements
    for (int i = 0; i < num.size(); i++) {

        int min_count_for_i = get_min_count(num, target - num[i]);

        if (min_count_for_i != INT_MAX) {
            min_count = min(min_count, min_count_for_i+1);
        }
    }
    return min_count;
}

// with dp, bottom up approach, memoization
int get_min_count(vector<int> &num, int target, vector<int> &dp) {

    if (target == 0) return 0;

    if (target < 0) return INT_MAX;

    if (dp[target] != -1) return dp[target];

    int min_count = INT_MAX;
    // run for all elements
    for (int i = 0; i < num.size(); i++) {

        int min_count_for_i = get_min_count(num, target - num[i], dp);

        if (min_count_for_i != INT_MAX) {
            min_count = min(min_count, min_count_for_i+1);
        }
    }
    return dp[target] = min_count;
}

// top down approach
int get_min_count_using_tabulation(vector<int> &num, int target) {

    vector<int> dp(target+1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= target; i++) {

        // all elements
        for (int j = 0; j < num.size(); j++) {

            if (i-num[j] >= 0 && dp[i-num[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1+dp[i-num[j]]);
            }
        }
    }

    if (dp[target] == INT_MAX) {
        return -1;
    }

    return dp[target];
}

int minimumElements(vector<int> &num, int x)
{
    
    // -------reccursion only--------
    /*
    int min_number_elements = get_min_count(num, x);

    if (min_number_elements == INT_MAX) 
        return -1;
    
    return min_number_elements;
    */

    // ------bottom to top-----
    /*
    // dp for all numbers < target, -- dp[index] <- it tells the min cost to get this number
    vector<int> dp(x+1, -1);
    int min_number_elements = get_min_count(num, x, dp);

    if (min_number_elements == INT_MAX) 
        return -1;
    
    return min_number_elements;
    */

    // ------top to bottom-------
    int min_number_elements = get_min_count_using_tabulation(num, x);

    if (min_number_elements == INT_MAX) 
        return -1;
    
    return min_number_elements;
}