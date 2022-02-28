class Solution{
    private:
    
    bool isSafe(vector<vector<int>> &m, int n,vector<vector<int>> &visited, string path, int x, int y ){
        
        if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && (m[x][y])==1){
            return true;
        }
        else{
            return false;
        }
        
    }
    
    void solve(vector<vector<int>> &m, int n,vector<vector<int>> &visited, string path, int x, int y, vector<string> &ans){
        
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y]=1;
        
        //up
        int newx=x-1;
        int newy=y;
        
        if(isSafe(m, n, visited, path, newx, newy)){
            path.push_back('U');
            solve(m, n, visited, path, newx, newy,ans);
            path.pop_back();
        }
        
        //down
        newx=x+1;
        newy=y;
        
        if(isSafe(m, n, visited, path, newx, newy)){
             path.push_back('D');
            solve(m, n, visited, path, newx, newy,ans);
            path.pop_back();
        }
        
        //left
        newx=x;
        newy=y-1;
        
        if(isSafe(m, n, visited, path, newx, newy)){
             path.push_back('L');
            solve(m, n, visited, path, newx, newy,ans);
            path.pop_back();
        }
        
         //right
        newx=x;
        newy=y+1;
        
        if(isSafe(m, n, visited, path, newx, newy)){
            path.push_back('R');
            solve(m, n, visited, path, newx, newy,ans);
            path.pop_back();
        }
        
        visited[x][y]=0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
       vector<string> ans;
       vector<vector<int>> visited=m;
       
       if(m[0][0]==0){
           return ans;
       }
       
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               visited[i][j]=0;
           }
       }
       
       int srcx=0;
       int srcy=0;
       string path="";
       
       solve(m,n,visited,path,srcx,srcy, ans);
       
       sort(ans.begin(),ans.end());
       
       return ans;
    }
};
