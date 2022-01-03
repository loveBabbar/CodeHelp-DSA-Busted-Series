import java.util.*;

public class Solution{
    public static int[][] pairSum(int[] arr, int s) {
        // Write your code here.
        
        List< List<Integer> > ans = new ArrayList<>();
   		
        Arrays.sort(arr);
        
       for(int i=0;i<arr.length; i++ )
       {
            for(int j = i+1; j<arr.length; j++) {
                if(arr[i] +arr[j] == s)
                {
                    List<Integer> temp = new ArrayList<>();
                    temp.add(Math.min(arr[i], arr[j]));
                    temp.add(Math.max(arr[i], arr[j]));
                    ans.add(temp);
                }
            }
       }
        	int[][] pairs = new int[ans.size()][2];
        	
        	int k = 0;
        
        	for(List<Integer> num:ans){
                pairs[k][0] = (int)num.get(0);
                pairs[k][1] = (int)num.get(1);
                k++;
            }
   			return pairs;
    }
}
