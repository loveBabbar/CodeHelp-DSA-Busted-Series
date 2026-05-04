#include <bits/stdc++.h>
using namespace std;

class Tabulation {
public:
    int tabulation(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>> dp(nums1.size()+1, vector<int> (2, 0));

        for (int index = nums1.size()-1; index > 0; index--) {

            for (int swaped = 0; swaped <= 1; swaped++) {

                int min_operations = INT_MAX;

                // *** get previous element of both vectors ***
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if (swaped) {
                    swap(prev1, prev2);
                }

                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    min_operations = dp[index+1][0];
                }

                // case 2: you swapped the element of both vector
                if (nums1[index] > prev2 && nums2[index] > prev1) {
                    min_operations = min(min_operations, 1 + dp[index+1][1]);
                }

                dp[index][swaped] = min_operations;
            }
        }

        return dp[1][0];
    }

    int space_optimised(vector<int>& nums1, vector<int>& nums2) {

        int swap_ = 0, no_swap = 0;

        int cur_swap = 0, cur_no_swap = 0;

        for (int index = nums1.size()-1; index > 0; index--) {

            for (int swaped = 0; swaped <= 1; swaped++) {

                int min_operations = INT_MAX;

                // *** get previous element of both vectors ***
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if (swaped) {
                    swap(prev1, prev2);
                }

                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    min_operations = no_swap;
                }

                // case 2: you swapped the element of both vector
                if (nums1[index] > prev2 && nums2[index] > prev1) {
                    min_operations = min(min_operations, 1 + swap_);
                }

                if (swaped) cur_swap = min_operations;
                else {
                    cur_no_swap = min_operations;
                }
            }
            swap_ = cur_swap;
            no_swap = cur_no_swap;
        }

        return min(swap_, no_swap);
    }
};

class Solution {
public:
    int recursion(vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {

        // index out of vector
        if (index == nums1.size()) return 0;

        int min_operations = INT_MAX;

        // *** get previous element of both vectors ***
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        // **catch**
        // if we swapped in previos recursive call then we have to swap the prev elements,
        // because we are not changing the values in vector, instaed just tracking the changes
        if (swapped) {
            swap(prev1, prev2);
        }

        // case 1: you do not swapped the elements

        // nums1 = 1, 2, 3, 8
        // nums2 = 5, 6, 7, 4
        if (nums1[index] > prev1 && nums2[index] > prev2) {
            min_operations = recursion(nums1, nums2, index+1, 0);
        }

        // case 2: you swapped the element of both vector
        if (nums1[index] > prev2 && nums2[index] > prev1) {
            min_operations = min(min_operations, 1 + recursion(nums1, nums2, index+1, 1));
        }

        return min_operations;
    }

    int memoization(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, 
        vector<vector<int>> &dp) {

        // index out of vector
        if (index == nums1.size()) return 0;

        if (dp[index][swapped] != -1) {
            return dp[index][swapped];
        }

        int min_operations = INT_MAX;

        // *** get previous element of both vectors ***
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        // **catch**
        // if we swapped in previos recursive call then we have to swap the prev elements,
        // because we are not changing the values in vector, instaed just tracking the changes
        if (swapped) {
            swap(prev1, prev2);
        }

        // case 1: you do not swapped the elements

        // nums1 = 1, 2, 3, 8
        // nums2 = 5, 6, 7, 4
        if (nums1[index] > prev1 && nums2[index] > prev2) {
            min_operations = memoization(nums1, nums2, index+1, 0, dp);
        }

        // case 2: you swapped the element of both vector
        if (nums1[index] > prev2 && nums2[index] > prev1) {
            min_operations = min(min_operations, 1 + memoization(nums1, nums2, index+1, 1, dp));
        }

        return dp[index][swapped] = min_operations;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        // craete dummy block at the start to handle edge cases
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        bool swapped = false;
        int start_index = 1;
        // return recursion(nums1, nums2, start_index, swapped);

        vector<vector<int>> dp(nums1.size(), vector<int> (2, -1));
        return memoization(nums1, nums2, start_index, swapped, dp);
    }
};