#include <bits/stdc++.h> 
using namespace std;

// solved by reccursion
int get_max_sum(vector<int> &nums, int num) {

    // nums = [4, 8]
    /*
        num =     index(8) = 1
        (include)/      \(excluded)
        num = -1 ->:            num = index(4)
            return 0    (include)/      \(excluded)
    */
    if (num < 0) return 0;

    if (num == 0) return nums[0];

    int include_num = get_max_sum(nums, num-2) + nums[num];
    int exclude_num = get_max_sum(nums, num-1);

    return max(include_num, exclude_num);
}

// solved by reccursion + memoization
int get_max_sum(vector<int> &nums, int num_i, vector<int> &dp) {

    if (num_i < 0) return 0;

    if (num_i == 0) return nums[0];

    if (dp[num_i] != -1) return dp[num_i];

    int include_num = get_max_sum(nums, num_i-2, dp) + nums[num_i];
    int exclude_num = get_max_sum(nums, num_i-1, dp);

    return dp[num_i] = max(include_num, exclude_num);
}

// tabulation
int solve(vector<int> &nums) {

    int size_nums = nums.size();

    vector<int> dp(size_nums, 0);

    dp[0] = nums[0];

    for (int i = 1; i < size_nums; i++) {

        int include = dp[i-2] + nums[i];
        int exclude = dp[i-1] + 0;

        dp[i] = max(include, exclude);
    }

    return dp[size_nums-1];
}

// space optimisation
int solve_(vector<int> &nums) {

    int size_nums = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < size_nums; i++) {

        int include = prev2 + nums[i];
        int exclude = prev1 + 0;

        int ans = max(include, exclude);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){

    int last_num_i = nums.size() - 1;

    // reccursion
    // int max_sum = get_max_sum(nums, last_num);

    // -------reccursion + memoization-------
    // vector<int> dp(last_num_i + 1, -1);
    // int max_sum = get_max_sum(nums, last_num_i, dp);
    // return max_sum;

    // tabulation
    // return solve(nums);

    // space optimisation
    return solve_(nums);

}