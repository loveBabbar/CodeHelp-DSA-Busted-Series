// https://leetcode.com/problems/pizza-with-3n-slices/submissions/1964604974

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursion(int index, int end_index, vector<int> &slices, int my_slices_left) {

        if (my_slices_left == 0 || index > end_index) {
            return 0;
        }

        // eat this slice, so next slice will be eaten by bob/alice
        int next_slice_index = index + 2;
        int take_slice = slices[index] + 
                         recursion(next_slice_index, end_index, slices, my_slices_left-1);

        // do not eat this slice
        next_slice_index = index + 1;
        int not_take_slice = 0 + recursion(next_slice_index, end_index, slices, my_slices_left);

        // return the maximum possible slice i can eat at this slice[index],
        // by taking or not taking
        return max(take_slice, not_take_slice);
    }

    int memoization(int index, int end_index, vector<int> &slices, 
        int my_slices_left, 
        vector<vector<int>> &dp
    ) {

        if (my_slices_left == 0 || index > end_index) {
            return 0;
        }

        if (dp[index][my_slices_left] != -1) {
            return dp[index][my_slices_left];
        }

        // eat this slice, so next slice will be eaten by bob/alice
        int next_slice_index = index + 2;
        int take_slice = slices[index] + 
                         memoization(next_slice_index, end_index, slices, my_slices_left-1, dp);

        // do not eat this slice
        next_slice_index = index + 1;
        int not_take_slice = 0 + memoization(next_slice_index, end_index, slices, my_slices_left, dp);

        // return the maximum possible slice i can eat at this slice[index],
        // by taking or not taking
        return dp[index][my_slices_left] = max(take_slice, not_take_slice);        
    }

    int tabulation(vector<int> &slices) {

        int k = slices.size();

        vector<vector<int>> dp1(k+2, vector<int> (k/3+2, 0));
        vector<vector<int>> dp2(k+2, vector<int> (k/3+2, 0));

        // **base case: dp already filled with 0**

        // **for 0th index**
        for (int index = k-2; index >= 0; index--) {

            for (int my_slices_left = 1; my_slices_left <= k/3; my_slices_left++) {

                    int next_slice_index = index + 2;
                    int take_slice = slices[index] + dp1[next_slice_index][my_slices_left-1];

                    next_slice_index = index + 1;
                    int not_take_slice = 0 + dp1[next_slice_index][my_slices_left];

                    dp1[index][my_slices_left] = max(take_slice, not_take_slice);
            }
        }
        int take_first = dp1[0][k/3];

        // **for first index**
        for (int index = k-1; index >= 1; index--) {

            for (int my_slices_left = 1; my_slices_left <= k/3; my_slices_left++) {

                    int next_slice_index = index + 2;
                    int take_slice = slices[index] + dp2[next_slice_index][my_slices_left-1];

                    next_slice_index = index + 1;
                    int not_take_slice = 0 + dp2[next_slice_index][my_slices_left];

                    dp2[index][my_slices_left] = max(take_slice, not_take_slice);
            }
        }
        int not_take_first = dp2[1][k/3];

        return max(take_first, not_take_first);
    }

    int space_optimised(vector<int> &slices) {

        int k = slices.size();

        vector<int> prev1(k+2,0);
        vector<int> cur1(k+2,0);
        vector<int> next1(k+2,0);

        vector<int> prev2(k+2,0);
        vector<int> cur2(k+2,0);
        vector<int> next2(k+2,0);

        // **base case: dp already filled with 0**

        // **for 0th index**
        for (int index = k-2; index >= 0; index--) {

            for (int my_slices_left = 1; my_slices_left <= k/3; my_slices_left++) {

                    int next_slice_index = index + 2;
                    int take_slice = slices[index] + next1[my_slices_left-1];

                    next_slice_index = index + 1;
                    int not_take_slice = 0 + cur1[my_slices_left];

                    prev1[my_slices_left] = max(take_slice, not_take_slice);
            }
            next1 = cur1;
            cur1 = prev1;
        }
        int take_first = cur1[k/3];

        // **for first index**
        for (int index = k-1; index >= 1; index--) {

            for (int my_slices_left = 1; my_slices_left <= k/3; my_slices_left++) {

                    int next_slice_index = index + 2;
                    int take_slice = slices[index] + next2[my_slices_left-1];

                    next_slice_index = index + 1;
                    int not_take_slice = 0 + cur2[my_slices_left];

                    prev2[my_slices_left] = max(take_slice, not_take_slice);
            }
            next2 = cur2;
            cur2 = prev2;
        }
        int not_take_first = cur2[k/3];

        return max(take_first, not_take_first);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        
        int k = slices.size();

    // recursive solution
    /*
        // take first elemet so remove last element
        int take_first = recursion(0, k-2, slices, k/3);

        // do not take first element and include last element
        int not_take_first = recursion(1, k-1, slices, k/3);

        return max(take_first, not_take_first);
    */

    // recursion + memoization
    /*
        // : we are updating dp array so thats why we need two frsh dp arrays, dp1 and dp2 **imp**
        vector<vector<int>> dp1(k+1, vector<int> (k/3+1, -1));
        int take_first = memoization(0, k-2, slices, k/3, dp1);

        vector<vector<int>> dp2(k+1, vector<int> (k/3+1, -1));
        int not_take_first = memoization(1, k-1, slices, k/3, dp2);

        return max(take_first, not_take_first);
    */

        // return tabulation(slices);

        return space_optimised(slices);
    }
};