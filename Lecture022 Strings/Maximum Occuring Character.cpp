//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int a[26]={0};
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            int number;
            if(ch>='a' && ch<='z'){
                number = ch-'a';
            }
            else{
                number = ch-'A';
            }
            a[number]++;
        }
        int maxi=-1,ans=0;
        for(int i=0;i<26;i++){
            if(maxi< a[i]){
                ans=i;
                maxi=a[i];
            }
        }
        char final = ans+'a';
        return final;
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
