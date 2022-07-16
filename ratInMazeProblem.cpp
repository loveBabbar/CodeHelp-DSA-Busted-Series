LECTURE 40 : RECURSION DAY 10
Lecture : - https://www.youtube.com/watch?v=GqtyVD-x_jY

Problem :- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

class Solution{
    private:
    bool isSafe(int x,int y,vector<vector<int>> &m,vector<vector<int>>visited,int n)
    {
        if((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) &&( m[x][y] == 1))
        {
           return true;
        }
        else
        {
            return false;
        }
    }
    void solve(vector<vector<int>> &m,vector<string>&ans,vector<vector<int>>visited,int x,int y,string path,int n)
    {
        // Base Case
        if(x >= n-1 && y >= n-1)
        {
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // 4 directions Down,Right,Left,Up

        // Down
        int newx = x+1;
        int newy = y;
        if(isSafe(newx,newy,m,visited,n))
        {
            path.push_back('D');
            solve(m,ans,visited,newx,newy,path,n);
            path.pop_back();
        }
        
        // Up
        newx = x-1;
        newy = y;
        if(isSafe(newx,newy,m,visited,n))
        {
            path.push_back('U');
            solve(m,ans,visited,newx,newy,path,n);
            path.pop_back();
        }
        
        // Left
        newx = x;
        newy = y-1;
        if(isSafe(newx,newy,m,visited,n))
        {
            path.push_back('L');
            solve(m,ans,visited,newx,newy,path,n);
            path.pop_back();
        }
        
        // Right
        newx = x;
        newy = y+1;
        if(isSafe(newx,newy,m,visited,n))
        {
            path.push_back('R');
            solve(m,ans,visited,newx,newy,path,n);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[0][0] == 0)
            return ans;
        
        vector<vector<int>> visited = m;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                visited[i][j] = 0; 
            }
        }
        
        int srcx = 0;
        int srcy = 0;
        
        string path = "";
        solve(m,ans,visited,srcx,srcy,path,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
