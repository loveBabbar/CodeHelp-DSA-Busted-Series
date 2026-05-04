// https://leetcode.com/problems/maximal-rectangle/submissions/1968028925

#include <bits/stdc++.h>
using namespace std;

// pre-requites- leetcode - 84 (largest rectangle in histogram)
class MySolution {
public:
    vector<int> nextSmallerElement(vector<int>& arr, int n) {

        stack<int> s;
        s.push(-1);

        // index of next smaller elements
        vector<int> ans(n);

        for (int i = n-1; i >= 0; i--) {

            int curr = arr[i];

            // trim the stack until found the smaller element
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr, int n) {

        stack<int> s;
        s.push(-1);

        // index of next smaller elements
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            int curr = arr[i];

            // trim the stack until found the smaller element
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;

        for (int i = 0; i < n; i++) {

            int l = heights[i];

            if (next[i] == -1) next[i] = n;
            int b = next[i] - prev[i] - 1;

            int newArea = l * b;

            area = max(area, newArea);
        }
        return area;
    }
};


class Solution {
    MySolution sol;
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int max_area = INT_MIN;

        vector<int> height (matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++) {

            // create histogram array
            for (int j = 0; j < height.size(); j++) {

                if (matrix[i][j] == '1') {
                    height[j]++;
                }
                else {
                    height[j] = 0;
                }
            }

            max_area = max(max_area, sol.largestRectangleArea(height));

        }

        return max_area;
    }
};