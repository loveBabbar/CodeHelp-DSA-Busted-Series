#include <bits/stdc++.h>
using namespace std;

int reccursion(int n, vector<int> &days, vector<int> &cost, int index) {

    if (index >= n) {
        return 0;
    }

    int day_pass = cost[0] + reccursion(n, days, cost, index+1);

    // move your index at correct position according to 7 days pass
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++);

    int week_pass = cost[1] + reccursion(n, days, cost, i);

    // move index according to 30 daya pass
    for (i = index; i < n && days[i] < days[index] + 30; i++);

    int month_pass = cost[2] + reccursion(n, days, cost, i);

    return min(day_pass, min(week_pass, month_pass));
}

int memoization(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp) {

    if (index >= n) {
        return 0;
    }

    if (dp[index] != -1) return dp[index];

    int day_pass = cost[0] + memoization(n, days, cost, index+1, dp);

    // move your index at correct position according to 7 days pass
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++);

    int week_pass = cost[1] + memoization(n, days, cost, i, dp);

    // move index according to 30 daya pass
    for (i = index; i < n && days[i] < days[index] + 30; i++);

    int month_pass = cost[2] + memoization(n, days, cost, i, dp);

    return dp[index] = min(day_pass, min(week_pass, month_pass));
}

int tabulation(int n, vector<int> &days, vector<int> &cost) {

    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    for (int k = n-1; k >= 0; k--) {
        int day_pass = cost[0] + dp[k+1];

        // move your index at correct position according to 7 days pass
        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++);

        int week_pass = cost[1] + dp[i];

        // move index according to 30 daya pass
        for (i = k; i < n && days[i] < days[k] + 30; i++);

        int month_pass = cost[2] + dp[i];

        dp[k] = min(day_pass, min(week_pass, month_pass));
    }

    return dp[0];
}

int space_optimised(int n, vector<int> &days, vector<int> &cost) {

    int ans = 0;

    // (day, cost_till_day)
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for (int day : days) {

        // ***remove expire days for month***
        while (!month.empty() && month.front().first + 30 <= day) month.pop();

        // ***remove expire days for week***
        while (!week.empty() && week.front().first + 7 <= day) week.pop();

        // ***add cost for current day***
        week.push({day, ans+cost[1]});
        month.push({day, ans+cost[2]});

        // ***update answer***
        int one_day = ans + cost[0];
        ans = min(one_day, min(week.front().second, month.front().second));
    }
    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // return reccursion(n, days, cost, 0);

    // return tabulation(n, days, cost);

    // space optimised
    return space_optimised(n, days, cost);
}