
public class Solution {

	public static void insertionSort(int n , int[] arr) {
			 if(n==1) return;
         	
            int j = arr.length-n+1;
            
            int temp = arr[j];
            
            while(j>0 && arr[j-1]>temp){
                arr[j] = arr[j-1];
                j--;
            }
            
            arr[j] = temp;
        
        	insertionSort(n-1,arr);
			        
	}
    
}
