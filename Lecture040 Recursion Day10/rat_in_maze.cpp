class Solution{
    private:
    bool isSafe(int x,int y,vector<vector<int>> m,int n,vector<vector<int>> visited){
        
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1){
            return true;
        }else{
            return false;
        }
        
    }
    void solve(vector<string> &ans,string path,vector<vector<int>> visited,int x,int y,vector<vector<int>> m,int n){
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // up
        int newx = x-1;
        int newy = y;
        if(isSafe(newx,newy,m,n,visited)){
            path.push_back('U');
            solve(ans,path,visited,newx,newy,m,n);
            path.pop_back();
        }
        
         // down
         newx = x+1;
         newy = y;
        if(isSafe(newx,newy,m,n,visited)){
            path.push_back('D');
            solve(ans,path,visited,newx,newy,m,n);
            path.pop_back();
        }
        
         // left
        newx = x;
        newy = y-1;
        if(isSafe(newx,newy,m,n,visited)){
            path.push_back('L');
            solve(ans,path,visited,newx,newy,m,n);
            path.pop_back();
        }
        
         // right
        newx = x;
        newy = y+1;
        if(isSafe(newx,newy,m,n,visited)){
            path.push_back('R');
            solve(ans,path,visited,newx,newy,m,n);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        int x = 0,y = 0;
        vector<string> ans;
        if(m[x][y] == 0){
            return ans;
        }
        vector<vector<int>> visited = m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        string path = "";
        solve(ans,path,visited,x,y,m,n);
        return ans;
    }
};