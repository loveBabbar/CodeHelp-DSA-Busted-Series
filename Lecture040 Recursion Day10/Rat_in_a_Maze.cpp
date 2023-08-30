
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution{
    private:
    
    bool isSafe(int i ,int j,vector<vector<int>> &m,vector<vector<int>> visited,int n){
       if( (i>=0 && i<n) && (j>=0 && j<n)  &&  (visited[i][j]==0 )  && (m[i][j]==1)  ){
           return true;
       }
       return false;
       
    }
    
    void solve(vector<vector<int>> &m, int n,vector<string> &ans,string path,vector<vector<int>> visited,int x,int y){
    
    //base Case
     if(x==n-1 && y==n-1){
         ans.push_back(path);
         return ;
     }
     
     visited[x][y]=1;
     
    //  FOR UP
     int newx=x-1;
     int newy=y;
     
     if(isSafe(newx,newy,m,visited,n)){
         path.push_back('U');
         solve(m,n,ans,path,visited,newx,newy);
         path.pop_back();
     }
     
     //  FOR DOWN
      newx=x+1;
      newy=y;
     
     if(isSafe(newx,newy,m,visited,n)){
         path.push_back('D');
         solve(m,n,ans,path,visited,newx,newy);
         path.pop_back();
     }
     
     
     //  FOR LEFT
      newx=x;
      newy=y-1;
     
     if(isSafe(newx,newy,m,visited,n)){
         path.push_back('L');
         solve(m,n,ans,path,visited,newx,newy);
         path.pop_back();
     }
     
     
     //  FOR RIGHT
      newx=x;
      newy=y+1;
     
     if(isSafe(newx,newy,m,visited,n)){
         path.push_back('R');
         solve(m,n,ans,path,visited,newx,newy);
         path.pop_back();
     }
     
     //For BackTrack
     visited[x][y]=0;
     
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        string path="";
            
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        int scrx=0;
        int scry=0;
        
        solve(m,n,ans,path,visited,scrx,scry);
        //To return ans in lexicographically increasing order.
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    int main() {
    Solution solution;

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = maze.size();

    vector<string> result = solution.findPath(maze, n);

    if (result.empty()) {
        cout << "No valid paths found." << endl;
    } else {
        cout << "Found paths:" << endl;
        for (const string &path : result) {
            cout << path << endl;
        }
    }

    return 0;
}
