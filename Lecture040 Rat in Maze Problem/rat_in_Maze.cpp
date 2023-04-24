//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    
    
    bool isSatisfied(vector<vector<int>>& m, int n, int x,int y,vector<vector<int>> visited)
    {
        if((x>=0&&x<n) && (y>=0&&y<n) && visited[x][y] == 0 && m[x][y] == 1)
            return true;
        return false;
    }
    
    
    void solve(vector<vector<int>>& m, int n, int x,int y,vector<string>& ans,vector<vector<int>> visited,string path)
    {
        //Base Case
        if(x == n-1 && y== n-1)
        {
            ans.push_back(path);
            return ;
        }
        
        visited[x][y] = 1;
        
        //Left Part
        int newx = x;
        int newy = y-1;
        if(isSatisfied(m,n,newx,newy,visited))
        {
            path.push_back('L');
            solve(m,n,newx,newy,ans,visited,path);
            path.pop_back();
        }
        
        //Right Part
        newx = x;
        newy = y+1;
        if(isSatisfied(m,n,newx,newy,visited))
        {
            path.push_back('R');
            solve(m,n,newx,newy,ans,visited,path);
            path.pop_back();
        }
        
        
        // Up Part
        newx = x-1;
        newy = y;
        if(isSatisfied(m,n,newx,newy,visited))
        {
            path.push_back('U');
            solve(m,n,newx,newy,ans,visited,path);
            path.pop_back();
        }
        
        // Down Part
        
        newx = x+1;
        newy = y;
        if(isSatisfied(m,n,newx,newy,visited))
        {
            path.push_back('D');
            solve(m,n,newx,newy,ans,visited,path);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> visited = m;
        
        if(m[0][0]==0)
        return ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=0;
            }
        }
        int srcx = 0;
        int srcy = 0;
        
        string path = "";
        
        solve(m,n,srcx,srcy,ans,visited,path);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends