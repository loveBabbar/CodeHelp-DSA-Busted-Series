import java.util.ArrayList;
public class Solution {
       
	public static int getPivot(ArrayList<Integer> arr, int n) {

    	int s = 0;
    	int e = n-1;
    	int mid = s + (e-s)/2;

    	while(s<e) {

        	if(arr.get(mid) >= arr.get(0))
        	{
           		s = mid+1;
        	}
        	else{
            	e = mid;
        	}
        	mid = s + (e-s)/2;
    	}
    	return s;
	}

	public static int binarySearch(ArrayList<Integer> arr, int s, int e, int key) {

    	int start = s;
    	int end = e;

    	int mid = start + (end-start)/2;

    	while(start <= end) {

        	if(arr.get(mid) == key) {
            	return mid;
       		}

        	
        	if(key > arr.get(mid)) {
            	start = mid + 1;
        	}
        	else{ 
            	end = mid - 1;
        	}

        	mid = start + (end-start)/2;
    	}
    
    	return -1;
	}


    
public static int findPosition(ArrayList<Integer> arr, int n, int k) {
    int pivot = getPivot(arr, n);
    if( k >= arr.get(pivot) && k <= arr.get(n-1))
    {
        return binarySearch(arr, pivot, n-1, k);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, k);
    }
    
    }

}

