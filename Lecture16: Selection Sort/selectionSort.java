import java.util.*;

public static void selectionSort(int[] arr, int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
            
        }
        swap(arr,minIndex,i);
    }
}

public void swap(int[] arr,int i,int j){
  int temp;
  
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
  
}
