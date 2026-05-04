#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

class Solution {
public:

    // Sort jobs in descending order of profit
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {

        // Step 1: sort jobs by profit
        sort(arr, arr + n, cmp);

        // Step 2: find max deadline
        int maxiDeadline = 0;
        for(int i = 0; i < n; i++) {
            maxiDeadline = max(maxiDeadline, arr[i].dead);
        }

        // Step 3: create schedule array
        vector<int> schedule(maxiDeadline + 1, -1);

        int count = 0;
        int maxProfit = 0;

        // Step 4: process jobs
        for(int i = 0; i < n; i++) {

            int currProfit = arr[i].profit;
            int currDeadline = arr[i].dead;

            // try to place job in latest possible free slot
            for(int k = currDeadline; k > 0; k--) {

                if(schedule[k] == -1) {
                    schedule[k] = arr[i].id;
                    count++;
                    maxProfit += currProfit;
                    break;
                }
            }
        }

        return {count, maxProfit};
    }
};