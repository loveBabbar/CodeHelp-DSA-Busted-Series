//This solution is meant for GFG question (Rat in a Maze Problem - I)
class Solution{
     public:
    bool issafe(int row,int col,int n,vector<vector<int>>& visited,vector<vector<int>>& m)
    {
        //3 conditions row col must be between 0 and n-1,visited array must be 0 that is the current path must not be repeated and third condition is to check whether path exist or not
        if((row>=0&&row<n) && (col>=0&&col<n) && visited[row][col]==0 && m[row][col]==1)
        {
            return true;
        }
        return false;
    }
    private:
    void pathtrace(vector<string>& ans,int row,int col,int n,string path,vector<vector<int>>& visited,vector<vector<int>>& m)
    {
        //Basecase(i.e. path has reached to its final destination)
        if(row==n-1 && col==n-1)
        {
            ans.push_back(path);
            return ;
        }
        
        visited[row][col]=1;//Firstly put the visited array as 1 as we are visiting the current node and last we have to put it 0 so that all other paths can be traced
        
        //Right movement
        if(issafe(row,col+1,n,visited,m))//issafe function call for checking if we can move or not
        {
             path.push_back('R');//First put R symbol as Right path 
             pathtrace(ans,row,col+1,n,path,visited,m);//Recursive call as we are inside safe condition so we can increment our column
             path.pop_back();//For recording all other paths we have to pop back the previous values
        }
        
         //Left movement
        if(issafe(row,col-1,n,visited,m))
        {
            
             path.push_back('L');
             pathtrace(ans,row,col-1,n,path,visited,m);
             path.pop_back();
        }
        
         //UP movement
        if(issafe(row-1,col,n,visited,m))
        {
            path.push_back('U');
             pathtrace(ans,row-1,col,n,path,visited,m);
             path.pop_back();
        }
        
         //Down movement
        if(issafe(row+1,col,n,visited,m))
        {
            path.push_back('D');
             pathtrace(ans,row+1,col,n,path,visited,m);
             path.pop_back();
        }
        
        visited[row][col]=0;//visited row col index put down to 0
       
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans; //for storing the ans
        if(m[0][0]==0)//Condition for checking for empty path
        {
            return ans;
        }
        int rowIndex=0;//Initial Row 
        int colIndex=0;//Initial Column
        vector<vector<int>> visited=m;//a 2D array for keeping the track of visited nodes of same size as m
        
        //Initializing the 2D array as 0 because no path is visited
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=0;
            }
        }
        string path="";//Variable for storing the path 
        
        pathtrace(ans,rowIndex,colIndex,n,path,visited,m);
        
        //Output is demanded in Lexicographic order so sort function is needed 
        sort(ans.begin(),ans.end());
        return ans;
    }
};