public class Solution{  

    public static int findUnique(int[] arr){
		//Your code goes here
        int ans = 0;
        for(int i= 0; i < arr.length; i++){
            ans = ans ^ arr[i];
        }
              return ans;
    }
}
