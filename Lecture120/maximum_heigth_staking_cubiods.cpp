#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(vector<int> base, vector<int> new_box) {

        if (new_box[0] <= base[0] && new_box[1] <= base[1] && new_box[2] <= base[2]) {
            return true;
        }
        return false;
    }

    // leetcode: 300
    int space_optimised(vector<vector<int>>& arr) {
        
        // TC: O(n**2)
        int n = arr.size();
        
        vector<int> cur_row(n+1, 0);
        vector<int> next_row(n+1, 0);
        
        // **base case: done**
        
        for (int cur = n-1; cur >= 0; cur--) {
            
            for (int prev = cur-1; prev >= -1; prev--) {
                
                int take = 0; // **important '0'**
                if (prev == -1 || check(arr[cur], arr[prev])) {
                    take = arr[cur][2] + next_row[cur+1];
                }
                
                int not_take = 0 + next_row[prev+1];
                
                cur_row[prev+1] = max(take, not_take);
            }
            
            // **important**
            next_row = cur_row;
        }
        return next_row[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        
        // step1: sort all dimensions for every cubiod
        // (height at last) -> maximum
        for (auto &cubiod: cuboids) {
            sort(cubiod.begin(), cubiod.end());
        }

        // step2: sort cubiods on the basis of base (width)
        sort(cuboids.begin(), cuboids.end());

        // step3: find LIS(longest increasing subsequence), for height
        // LIS -> leetcode 300
        return space_optimised(cuboids);
    }
};