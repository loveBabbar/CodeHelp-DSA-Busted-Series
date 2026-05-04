#include <iostream>
#include <vector>
using namespace std;


class Solution {
  private:
    int reccursion(vector<vector<int>> &mat, int i, int j, int &maxi) {
        
        if (i >= mat.size() || j >= mat[0].size()) return 0;
        
        int go_right_count_1 = reccursion(mat, i, j+1, maxi);
        int go_diagonal_count_1 = reccursion(mat, i+1, j+1, maxi);
        int go_down_count_1 = reccursion(mat, i+1, j, maxi);
        
        if (mat[i][j] == 1) {
            
            int ans = 1 + min(go_right_count_1, min(go_diagonal_count_1, go_down_count_1));
            maxi = max(maxi, ans);
            return ans;
        }
        else {
            return 0;
        }
    }
    
    int memoization(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp) {
        
        if (i >= mat.size() || j >= mat[0].size()) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int go_right_count_1 = memoization(mat, i, j+1, maxi, dp);
        int go_diagonal_count_1 = memoization(mat, i+1, j+1, maxi, dp);
        int go_down_count_1 = memoization(mat, i+1, j, maxi, dp);
        
        if (mat[i][j] == 1) {
            
            dp[i][j] = 1 + min(go_right_count_1, min(go_diagonal_count_1, go_down_count_1));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else {
            return dp[i][j] = 0;
        }
    }
    
    void tabulation(vector<vector<int>>& mat, int &maxi) {
        
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(mat.size()+1, vector<int> (mat[0].size()+1, -0));
        
        // ***base case***
        // already initialed dp with 0
        
        for (int i = row-1; i >= 0; i--) {
            
            for (int j = col-1; j >= 0; j--) {
                
                int go_right_count_1 = dp[i][j+1];
                int go_diagonal_count_1 = dp[i+1][j+1];
                int go_down_count_1 = dp[i+1][j];
                
                if (mat[i][j] == 1) {
                    
                    dp[i][j] = 1 + min(go_right_count_1, min(go_diagonal_count_1, go_down_count_1));
                    maxi = max(maxi, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
                
            }
        }
    }
    
    void space_optimised(vector<vector<int>>& mat, int &maxi) {
        
        int row = mat.size();
        int col = mat[0].size();
        
        std::vector<int> curr(col+1, 0);
        std::vector<int> next(col+1, 0);
        
        // ***base case***
        // already initialed dp with 0
        
        for (int i = row-1; i >= 0; i--) {
            
            for (int j = col-1; j >= 0; j--) {
                
                int go_right_count_1 = curr[j+1];
                int go_diagonal_count_1 = next[j+1];
                int go_down_count_1 = next[j];
                
                if (mat[i][j] == 1) {
                    
                    curr[j] = 1 + min(go_right_count_1, min(go_diagonal_count_1, go_down_count_1));
                    maxi = max(maxi, curr[j]);
                }
                else {
                    curr[j] = 0;
                }
                
            }
            next = curr;
            
        }
    }
    
  public:
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        
        // int maxi = 0;
        // return reccursion(mat, 0, 0, maxi);
        
        // int maxi = 0;
        // vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
        // memoization(mat, 0, 0, maxi, dp);
        // return maxi;
        
        // int maxi = 0;
        // tabulation(mat, maxi);
        // return maxi;
        
        int maxi = 0;
        space_optimised(mat, maxi);
        return maxi;
        
    }
};