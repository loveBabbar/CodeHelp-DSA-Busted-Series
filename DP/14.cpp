/*
@Largest square formed in a matrix

Example 1:
Input: n = 2, m = 2
mat = {{1, 1},
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the
maximum sized sub-matrix in this case.

Example 2:
Input: n = 2, m = 2
mat = {{0, 0},
       {0, 0}}
Output: 0
Explaination: There is no 1 in the matrix.
Your Task:
You do not need to read input or print anything. Your task is to complete the function maxSquare() which takes n, m and mat as input parameters and returns the size of the maximum square sub-matrix of given matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)


*/

// CODE LINK : https://leetcode.com/problems/maximal-square/description/
// GFG LINK : https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 Using Normal Recursion
    int solve(vector<vector<char>> &matrix, int row, int col, int &maxi)
    {
        // base-case
        if (row >= matrix.size() || col >= matrix[0].size())
            return 0;

        // recursive calls
        int right = solve(matrix, row, col + 1, maxi);
        int diagnal = solve(matrix, row + 1, col + 1, maxi);
        int down = solve(matrix, row + 1, col, maxi);

        // if current element is itself a square
        if (matrix[row][col] == '1')
        {
            int ans = 1 + min(right, min(diagnal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else
        {
            return 0; // if not's
        }
    }
    // Approach-2 Using Recursion + Memoisation
    int solveMemo(vector<vector<char>> &matrix, int row, int col, int &maxi, vector<vector<int>> &dp)
    {
        // base-case
        if (row >= matrix.size() || col >= matrix[0].size())
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        // recursive calls
        int right = solve(matrix, row, col + 1, maxi);
        int diagnal = solve(matrix, row + 1, col + 1, maxi);
        int down = solve(matrix, row + 1, col, maxi);

        // if current element is itself a square
        if (matrix[row][col] == '1')
        {
            int ans = 1 + min(right, min(diagnal, down));
            maxi = max(maxi, ans);
            dp[row][col] = ans;
        }
        else
        {
            dp[row][col] = 0; // if not's
        }

        return dp[row][col];
    }
    // Approach-3 Using Tabulation Method
    void solveTabulation(vector<vector<char>> &matrix, int &maxi)
    {

        int row = matrix.size();
        int col = matrix[0].size();

        // why row + 1 & col + 1 becuase let say while itereting diagnal = dp[i+1][j+1] in case i&j edge par hua & 1+ ho gya code fat jayga
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0)); // filling ans with 0 because while calculating  in case answer -1+1 hua toh ans 0 ho jayga but 1 hona chaye is case mein!

        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {

                int right = dp[i][j + 1];
                int diagnal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                // if current element is itself a square
                if (matrix[i][j] == '1')
                {
                    int ans = 1 + min(right, min(diagnal, down));
                    maxi = max(maxi, ans);
                    dp[i][j] = ans;
                }
                else
                {
                    dp[i][j] = 0; // if not's
                }
            }
        }
    }
    // Approach-4 Applying Space Optimisation along with tabulation
    void solveSpaceOpt(vector<vector<char>> &matrix, int &maxi)
    {

        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> curr(col + 1, 0);
        vector<int> next(col + 1, 0);

        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {

                int right = curr[j + 1];
                int diagnal = next[j + 1];
                int down = next[j];

                // if current element is itself a square
                if (matrix[i][j] == '1')
                {
                    int ans = 1 + min(right, min(diagnal, down));
                    maxi = max(maxi, ans);
                    curr[j] = ans; // current row mein automatically change ho range hain that's why it's working as curr = ans
                }
                else
                {
                    curr[j] = 0; // if not's
                }
            }
            next = curr;
        }
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int ans = 0;

        // Approach-1
        solve(matrix, 0, 0, ans);
        return ans * ans;

        // Approach-2
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        solveMemo(matrix, 0, 0, ans, dp);
        return ans * ans;

        // Approach-3
        solveTabulation(matrix, ans);
        return ans * ans;

        // Approach-4
        solveSpaceOpt(matrix, ans);
        return ans * ans;
    }
};