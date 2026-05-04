// https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        
        if (N * 6 < M * 7 && S > 6) return -1;
        
        if (M > N) return -1;
        
        int sundays = S / 7;
        
        int buy_day = S - sundays;
        int total_food_required = S * M;
        int min_day_buy = 0;
        
        if (total_food_required % N == 0) {
            min_day_buy = (S * M) / N;
        }
        else {
            min_day_buy = (S * M) / N + 1;
        }
        
        if (min_day_buy <= buy_day) {
            return min_day_buy;
        }
        return -1;
    }
};