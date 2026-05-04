#include <iostream>
#include <vector>
#include <limits>
#include <climits>
using namespace std;

class Solution {
  private:
    int reccursion(int n) {
        
        if (n == 0) return 0;
        
        int ans = n;
        
        // ***run for all elements***
        for (int i = 1; i*i <= n; i++) {
            
            int temp = i * i;
            ans = min(ans, reccursion(n - temp) + 1);
        }
        return ans;
    }
    
    int memoization(int n, vector<int> &dp) {
        
        if (n == 0) return 0;
        
        if (dp[n] != -1) {
            return dp[n];
        }
        
        int ans = n;
        
        // ***run for all elements***
        for (int i = 1; i*i <= n; i++) {
            
            int temp = i * i;
            ans = min(ans, memoization(n - temp, dp) + 1);
        }
        return dp[n] = ans;
    }
    
    int tabulation(int n) {
        
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j*j <= n; j++) {
                int temp = j*j;
                
                if (i - temp >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i-temp]);
                }
            }
        }
        return dp[n];
    }
    
  public:
    int minSquares(int n) {
        
        // return reccursion(n);
        
        // vector<int> dp(n+1, -1);
        // return memoization(n, dp);
        
        return tabulation(n);
    }
};