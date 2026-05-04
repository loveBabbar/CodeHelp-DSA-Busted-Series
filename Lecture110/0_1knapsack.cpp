#include <bits/stdc++.h> 
using namespace std;

int reccursion(vector<int> &weight, vector<int> &value, 
				int cur_index, int capacity_knapsack) {

	// reached at last item, that is at 0th index, (started from last)
	if (cur_index == 0) {

		// if knapsack have capicity, rob item,, (used bit of extra variables for simplicity)
		int start_index = 0;
		if (capacity_knapsack >= weight[start_index]) {
			return value[start_index];
		}
		else {
			// **full**
			return 0;
		}
	}

	// **include current item and move next**
	int include_cur_item = 0;
	if (weight[cur_index] <= capacity_knapsack) {
		include_cur_item = value[cur_index] + reccursion(weight, value, cur_index-1, capacity_knapsack - weight[cur_index]);	
	}

	// **exclude current item and move next**
	int exclude_cur_item = 0 + reccursion(weight, value, cur_index-1, capacity_knapsack);

	// **find best of both**
	int pick_best = max(include_cur_item, exclude_cur_item);

	return pick_best;
}

int memoization(vector<int> &weight, vector<int> &value, 
				int cur_index, int capacity_knapsack, vector<vector<int>> &dp) {

	// reached at last item, that is at 0th index, (started from last)
	if (cur_index == 0) {

		// if knapsack have capicity, rob item,, (used bit of extra variables for simplicity)
		int start_index = 0;
		if (capacity_knapsack >= weight[start_index]) {
			return value[start_index];
		}
		else {
			// **full**
			return 0;
		}
	}

	if (dp[cur_index][capacity_knapsack] != -1) {
		return dp[cur_index][capacity_knapsack];
	}

	// **include current item and move next**
	int include_cur_item = 0;
	if (weight[cur_index] <= capacity_knapsack) {
		include_cur_item = value[cur_index] + memoization(weight, value, cur_index-1, capacity_knapsack - weight[cur_index], dp);	
	}

	// **exclude current item and move next**
	int exclude_cur_item = 0 + memoization(weight, value, cur_index-1, capacity_knapsack, dp);

	// **find best of both**
	dp[cur_index][capacity_knapsack] = max(include_cur_item, exclude_cur_item);

	return dp[cur_index][capacity_knapsack];
}

int tabulation(vector<int> &weight, vector<int> &value, 
				int cur_index, int capacity_knapsack) {
    
    // understand this, read this again that how to solve this using a dp.
    // and how to optimise the space
}



int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// knapsack is like a bag;

	// ----brute force: reccursion------
	// starting from last, you can from start too
	// return reccursion(weight, value, n-1, maxWeight);

	// ***reccursion + memoization***
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return memoization(weight, value, n-1, maxWeight, dp);
}

class Knapsack {

	// ***aditya verma***
	int reccursion(vector<int> &weight, vector<int> &value, 
				int cur_index, int capacity_knapsack) {
		
		if (cur_index == 0 || capacity_knapsack == 0) return 0;

		if (weight[cur_index-1] <= capacity_knapsack) {

			return max(value[cur_index-1] + reccursion(weight, value, cur_index-1, capacity_knapsack - weight[cur_index-1]),
					reccursion(weight, value, cur_index-1, capacity_knapsack));
		}

		else if (weight[cur_index-1] > capacity_knapsack) {
			return reccursion(weight, value, cur_index-1, capacity_knapsack);
		}
	}
};