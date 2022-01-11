public class Solution {
	public static void selectionSort(int arr[], int n) {
		
        if(n==1) return;
        
        int min_index = 0;
        
        int min = Integer.MAX_VALUE;
            
        int length = arr.length;
        
        for(int i=length-1;i>=length-n;i--){
            if(min>arr[i]){
                min = arr[i];
                min_index = i;
            }
        }
        
        swap(arr,min_index,length-n);
        
        selectionSort(arr,n-1);
	}
    
    public static void swap(int[] arr,int i,int j){
        int temp;
        
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
