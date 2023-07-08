#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        // s.find(part) function does not find the substring part within the string s, it returns a special value called string::npos
        // s.find(part) returns a value greater than the s.length() , when part is not found 
        // s.length()!=0 &&  --> so we can ignore this condition in the while loop
       
        while( s.find(part) < s.length()) {   
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};
