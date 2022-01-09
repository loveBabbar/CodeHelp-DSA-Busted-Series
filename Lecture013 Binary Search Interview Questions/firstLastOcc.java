import java.util.ArrayList;
import javafx.util.Pair;
  public class Solution {
   
	static int firstOcc(ArrayList<Integer> arr, int n, int key)
    {
    
    	int start = 0, end = n-1;
    	int mid = start + (end-start)/2;
    	int ans = -1;
    
    	while(start<=end)
        {
        	if(arr.get(mid)==key)
            {
            	ans = mid;
           		end = mid-1;
       		}
        	else if(key > arr.get(mid))
            {
            	start = mid + 1;
        	}
        	else if(key < arr.get(mid))
            {
            	end = mid - 1;
        	}
        
         	mid = start + (end-start)/2;
    	}
    	return ans;
	}

	static int lastOcc(ArrayList<Integer> arr, int n, int key)
    {
    	int start = 0, end = n-1;
    	int mid = start + (end-start)/2;
    	int ans = -1;
    
    	while(start<=end)
        {
        	if(arr.get(mid)==key)
            {
            	ans = mid;
           		start = mid+1;
        	}
        	else if(key > arr.get(mid))
            {
            	start = mid + 1;
        	}
        	else if(key < arr.get(mid))
            {
            	end = mid - 1;
       		}
        
         	mid = start + (end-start)/2;
    	}
    return ans;
}

	public static Pair<Integer, Integer> firstAndLastPosition(ArrayList<Integer> arr, int n, int k) {
       
    	int first = firstOcc(arr, n, k);
    	int second = lastOcc(arr, n, k);
        Pair p = new Pair(first, second);
    
    return p;
    }

};
