#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int reccursion(vector<int>& obstacles, int cur_lane, int cur_position) {

        int target_position = obstacles.size() - 1;

        // reached at answer
        if (cur_position == target_position) {
            return 0;
        }

        int obstacle_at_lane_after_this_position = obstacles[cur_position+1];

        // move straight
        if (obstacle_at_lane_after_this_position != cur_lane) {

            int next_position = cur_position + 1;
            return reccursion(obstacles, cur_lane, next_position);
        }

        else {

            // obstacle foun at same lane in next position, jumb

            int jumps = INT_MAX;

            // explore all lanes, means all position paths, and return minimum jump wala path
            for (int next_lane = 1; next_lane <= 3; next_lane++) {

                // check for edge cases
                if (cur_lane != next_lane && obstacles[cur_position] != next_lane)
                    jumps = min(jumps, 1+reccursion(obstacles, next_lane, cur_position));
            }
            return jumps;
        }
    }

    int memoization(vector<int>& obstacles, int cur_lane, int cur_position, 
                    vector<vector<int>> &dp) {

        int target_position = obstacles.size() - 1;

        // reached at answer
        if (cur_position == target_position) {
            return 0;
        }

        if (dp[cur_position][cur_lane] != -1) {
            return dp[cur_position][cur_lane];
        }

        int obstacle_at_lane_after_this_position = obstacles[cur_position+1];

        // move straight
        if (obstacle_at_lane_after_this_position != cur_lane) {

            int next_position = cur_position + 1;
            return dp[cur_position][cur_lane] = memoization(
                obstacles,
                cur_lane, 
                next_position, 
                dp
            );
        }

        else {

            // obstacle foun at same lane in next position, jumb

            int jumps = INT_MAX;

            // explore all lanes, means all position paths, and return minimum jump wala path
            for (int next_lane = 1; next_lane <= 3; next_lane++) {

                // check for edge cases
                if (cur_lane != next_lane && obstacles[cur_position] != next_lane)
                    jumps = min(jumps, 1+memoization(obstacles, next_lane, cur_position, dp));
            }
            return dp[cur_position][cur_lane] = jumps;
        }
    }

    int tabulation(vector<int>& obstacles) {

        int total_positions = obstacles.size();
        int total_lanes = 3;

        vector<vector<int>> dp(total_lanes+1, vector<int> (total_positions, 1e9));

        // initially jumps at target is 0, then go back
        for (int lane = 0; lane <= total_lanes; lane++)
            dp[lane][total_positions-1] = 0;

        for (int cur_pos = total_positions-2; cur_pos >= 0; cur_pos--) {

            for (int cur_lane = 1; cur_lane <= 3; cur_lane++) {

                int obstacle_at_lane_after_this_position = obstacles[cur_pos+1];

                // move straight
                if (obstacle_at_lane_after_this_position != cur_lane) {

                    int next_position = cur_pos + 1;
                    dp[cur_lane][cur_pos] = dp[cur_lane][next_position];
                }
                else {
                    // obstacle found at same lane in next position, jumb

                    int jumps = INT_MAX;

                    // explore all lanes, 
                    // means all position paths, and return minimum jump wala path
                    for (int next_lane = 1; next_lane <= 3; next_lane++) {

                        // check for edge cases
                        if (cur_lane != next_lane && obstacles[cur_pos] != next_lane)
                            jumps = min(
                                jumps, 
                                1 + dp[next_lane][cur_pos+1]
                            );  // +1 is important
                    }
                    dp[cur_lane][cur_pos] = jumps;
                }
            }
        }

        return min(
            dp[2][0],
            min(1 + dp[1][0], 1 + dp[3][0])
        );
    }

    int space_optimised(vector<int>& obstacles) {

        int total_positions = obstacles.size();
        int total_lanes = 3;

        vector<int> cur(total_lanes+1);
        vector<int> next(total_lanes+1);

        // initially jumps at target is 0, then go back
        for (int lane = 0; lane <= total_lanes; lane++)
            next[lane] = 0;

        for (int cur_pos = total_positions-2; cur_pos >= 0; cur_pos--) {

            for (int cur_lane = 1; cur_lane <= 3; cur_lane++) {

                int obstacle_at_lane_after_this_position = obstacles[cur_pos+1];

                // move straight
                if (obstacle_at_lane_after_this_position != cur_lane) {

                    int next_position = cur_pos + 1;
                    cur[cur_lane] = next[cur_lane];
                }
                else {
                    // obstacle found at same lane in next position, jumb

                    int jumps = INT_MAX;

                    // explore all lanes, 
                    // means all position paths, and return minimum jump wala path
                    for (int next_lane = 1; next_lane <= 3; next_lane++) {

                        // check for edge cases
                        if (cur_lane != next_lane && obstacles[cur_pos] != next_lane)
                            jumps = min(
                                jumps, 
                                1 + next[next_lane]
                            );  // +1 is important
                    }
                    cur[cur_lane] = jumps;
                }
            }
            next = cur;
        }

        return min(
            cur[2],
            min(1 + cur[1], 1 + cur[3])
        );
    }

public:
    int minSideJumps(vector<int>& obstacles) {

    /*
        int starting_lane = 2;
        int starting_position = 0;
        
         return reccursion(obstacles, starting_lane, starting_position);
    */

    /*
        int number_of_lanes = 3;
        vector<vector<int>> dp(obstacles.size(), vector<int> (number_of_lanes+1, -1));
         return memoization(obstacles, starting_lane, starting_position, dp);

    */
        // return tabulation(obstacles);

        return space_optimised(obstacles);
    }
};