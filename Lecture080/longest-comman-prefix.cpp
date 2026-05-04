#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";

    // traverse all charecters of first string
    for (int i = 0; i < arr[0].length(); i++) {

        char ch = arr[0][i];

        bool match = true;

        // compaire ch with rest of the string
        for (int j = 1; j < n; j++) {

            // not matched
            if (arr[j].size() < i || ch != arr[j][i]) {
                match = false;
                break;
            }
        }
        if (match == false) {
            break;
        }
        else {
            ans.push_back(ch);
        }
    }
    return ans;
}
