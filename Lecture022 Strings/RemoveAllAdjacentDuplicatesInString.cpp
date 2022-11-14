#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        vector<char> dupl;

        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (!dupl.empty())
            {
                if (dupl.back() == s[i])
                {
                    dupl.pop_back();
                    continue;
                }
            }
            dupl.push_back(s[i]);
        }
        string result(dupl.begin(), dupl.end());
        return result;
    }
};
