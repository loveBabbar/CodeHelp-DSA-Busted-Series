//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Time complexity- O(n)

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int n=str.size();
        int count[128]={0};      //This is initial the value from 0;
        
        for(int i=0; i<n; i++){
            count[str[i]-'a']++;       //This will store the no. of count at ith index. This is the only logic.
        }
        
        int max=-1;
        char ch;
        for(int i=0; i<128; i++){
            if(max<count[i]){
                max=count[i];
                ch=i+'a';          //This will change the integer into character and update the ch.
            }
        }
        return ch;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends



// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1
