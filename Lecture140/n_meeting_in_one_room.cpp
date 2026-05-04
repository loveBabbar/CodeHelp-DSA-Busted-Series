// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    // compaire based on ending time will sorting
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        vector<pair<int, int>> v;
        
        // **sort timing on the basis of end time**
        for (int i = 0; i < start.size(); i++) {
            
            pair<int, int> p = {start[i], end[i]};
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int count = 1;
        int ans_end = v[0].second;
        
        for (int i = 1; i < start.size(); i++) {
            
            // next meeting is only possible when already running meeting ending time is less than next meeting start time
            if (v[i].first > ans_end) {
                count++;
                
                ans_end = v[i].second;
            }
        }
        return count;
    }
};