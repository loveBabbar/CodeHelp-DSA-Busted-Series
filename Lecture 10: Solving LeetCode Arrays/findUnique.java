public class Solution{  

    public static int findUnique(int[] arr){
		//Your code goes here
        
        int ans = 0;
        
        for(int num:arr) ans ^= num;
        
        return ans;
    }
}
