//GFG Solution
class Solution {
    public static boolean isSafe(int x , int y , int n , int[][] m , int[][] visited)
    {
        if(x < 0 || y < 0 || x > n-1 || y > n-1 || m[x][y] == 0 || 
        visited[x][y] == 1 )
            return false;
        else
            return true;
    }
    
    public static void solve(String path ,int[][] visited , int[][] m ,
            int n, int x, int y , ArrayList<String> ans)
            {
                //Base case
                if(x == n-1 && y == n-1)
                {
                    ans.add(path);
                    return ;
                }
                
                visited[x][y] = 1;


                //4 Choices  D , L ,R ,U.
                
                // Down
                int newx = x + 1;
                int newy = y;
                if(isSafe(newx,newy,n,m,visited))
                {
                    path = path + "D";
                    solve(path , visited , m , n , newx , newy ,ans);
                    path = path.substring(0 , path.length() - 1);
                    
                }
                // Left
                newx = x ;
                newy = y - 1;
                if(isSafe(newx,newy,n,m,visited))
                {
                    //We can pass path+"L" directly in the solve function call, inorder to avoid two extra lines of code , 
                    // like in the case where the rat moves down.
                    solve(path+"L" , visited , m , n , newx , newy, ans);
                    
                }
                // Right
                newx = x ;
                newy = y + 1;
                if(isSafe(newx,newy,n,m,visited))
                {
                   
                    solve(path+"R" , visited , m , n , newx , newy ,ans);
                    
                }
                // Up
                newx = x - 1;
                newy = y;
                if(isSafe(newx,newy,n,m,visited))
                {
                    
                    solve(path+"U" , visited , m , n , newx , newy ,ans);
                    
                }
                visited[x][y] = 0;
                
                
            }
    public static ArrayList<String> findPath(int[][] m, int n) {
        // Your code here
        ArrayList<String> ans = new ArrayList<>();
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
            return ans;
            
        int[][] visited = new int[n][n];

        int srcx = 0;
        int srcy = 0;
        
        String path = "";
        solve(path , visited , m , n , srcx , srcy , ans);
        Collections.sort(ans);
        return ans;
    }
}