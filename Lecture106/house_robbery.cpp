#include <bits/stdc++.h> 
using namespace std;

long long int solve(vector<int> &nums) {
        /* "space optimisarion (dp)" */
        
        long long int size_nums = nums.size();

        long long int prev2 = 0;
        long long int prev1 = nums[0];

        for (int i = 1; i < size_nums; i++) {

            long long int include = prev2 + nums[i];
            long long int exclude = prev1 + 0;

            long long int ans = max(include, exclude);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.

    int n = valueInHouse.size();

    if (n == 1) return valueInHouse[0];
    
    vector<int> first, second;
    for (int i = 0; i < n; i++) {

        if (i != n-1) {
            first.push_back(valueInHouse[i]);
        }

        if (i != 0) {
            second.push_back(valueInHouse[i]);
        }
    }
    return max(solve(first), solve(second));
}