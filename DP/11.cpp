/*

@ Get Minimum Squares
@ Perfect Squares

Example 1:
Input: N = 100
Output: 1
Explanation: 10 * 10 = 100

Example 2:
Input: N = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6

Your Task:
You don't need to read or print anyhting. Your task is to complete the function MinSquares() which takes N as input parameter and returns minimum number of squares needed to make N.


Expcted Time Complexity: O(N * sqrt(N) )
Expected Space Complexity: O(N)


Constraints:
1 <= N <= 10000

*/

// CODE LINK : https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1
// CODE LINK : https://leetcode.com/problems/perfect-squares/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	// Approach-1 Using Normal Recursion
	int solve(int n)
	{
		// base-case 0 se perfect square nhi bana skta because of constraint 1 <= N <= 10000
		if (n == 0)
			return 0;

		int ans = n; // making squares using value 1 only. so no. of 1 required will be equal to n

		for (int i = 1; i * i <= n; i++)
		{
			ans = min(ans, 1 + solve(n - i * i));
		}

		return ans;
	}
	// Approach-2 Using Recursion + Memoisation
	int solveMemo(int n, vector<int> &dp)
	{
		// step-1 base case
		if (n == 0)
			return 0;

		// step-3
		if (dp[n] != -1)
			return dp[n];

		// step-2
		int ans = n;
		for (int i = 1; i * i <= n; i++)
		{
			ans = min(ans, 1 + solveMemo(n - i * i, dp));
		}
		dp[n] = ans; // storing answer in dp

		return dp[n];
	}
	// Approach-3 Using Tabulation Method
	int solveTab(int n)
	{
		// step-1 creation of dp array
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j * j <= n; j++)
			{
				// making sure index with in range
				if (i - j * j >= 0)
				{
					dp[i] = min(dp[i], 1 + dp[i - j * j]);
				}
			}
		}

		return dp[n];
	}
	int numSquares(int n)
	{
		// Approach-1
		return solve(n);

		// Approach-2
		vector<int> dp(n + 1, -1);
		return solveMemo(n, dp);

		// Approach-3
		return solveTab(n);
	}
};