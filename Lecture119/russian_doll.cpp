#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void my_sort(vector<vector<int>>& v) {

        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];       // descending for 2nd column
            return a[0] < b[0];       // ascending for 1st column
        });
    }

    int dp_with_binary_search(int n, vector<int> a) {
        
        // TC: O(nlogn)
        if (n == 0) {
            return 0;
        }
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for (int i = 1; i < n; i++) {
            
            // push element in last in vector, 
            // if last element at last is < a[i]
            if (a[i] > ans.back()) {
                ans.push_back(a[i]);
            }
            else {
                
                // find index of just badda element
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                
                ans[index] = a[i];
            }
        }
        return ans.size();
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        /*
            pre-requites: solve LIS (longest increasing sequence, leetcode: 300)
        */
        
        // sort on rules
        my_sort(envelopes);

        // extract height, that is second column of envelopes
        vector<int> heights;
        for (auto &e : envelopes) {
            heights.push_back(e[1]);
        }

        // find LIS on 2nd column
        return dp_with_binary_search(envelopes.size(), heights);
    }
};