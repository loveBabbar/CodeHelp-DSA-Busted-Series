#include <bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;

    int maxFreq = 0;
    for (int i = 0; i < arr.size(); i++) {

        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    // 4 -5 1
    /*
        4  -> 1, maxFreq = 1
        -5 -> 1, no change
        1  -> 1, no change
    */
    int ans;
    // now can not traverse in unordered map now, bc it do not preserve order
    for (auto i : arr) {

        if (count[i] == maxFreq) {
            ans = i;
            break;
        }
    }
    return ans;
}