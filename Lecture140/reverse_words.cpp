// https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string reverseWords(string &s) {
        
        string ans = "";
        string temp = "";
        
        for (int i = s.length()-1; i >= 0; i--) {
            
            if (s[i] == '.') {
                
                if (!temp.empty()) {
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                    ans.push_back('.');
                    temp = "";
                }
            }
            else {
                temp.push_back(s[i]);
            }
        }
        
        // last word
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        
        // remove last extra dot if exists
        if (!ans.empty() && ans.back() == '.') {
            ans.pop_back();
        }
        
        return ans;
    }
};