import java.util.*;
class BubbleSort {
    int[] bubbleSort(int arr[], int n) {
        for(int i = 1 ; i < n; i++) {
            //for round 1 to n-1
            boolean swapped = false;
            
            for(int j = 0 ; j < n-i ; j++) {
                
                //process element till n-i th index
                if(arr[j] > arr[j+1]) {

                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swapped = true;
                }
                
            }
            
            if(swapped == false) {
                //already sorted
                break;
            }
               
        }
        return arr;
    }
}