
import java.util.Scanner;
import java.util.Arrays;
public class SelectionSort {
    // Selection Sort
    public static void main(String []args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take SIZE of 1D Array from the USER
        System.out.print(" Enter SIZE of 1D Array: ");
        int n = sc.nextInt();
        // Creating Array of Required SIZE
        int [] arr = new int[n];
        // Fill the Array by taking inputs from the USER
        System.out.print(" Enter " + n + " Elements: ");
        for(int i=0; i<arr.length; i++)
            arr[i] = sc.nextInt();
        // Display the Input Array Before Sorting
        System.out.println(" Array Before Sorting is: " + Arrays.toString(arr));
        // Apply Selection Sort
        selectionSort(arr);
        // Display resultant Array (i.e Sorted Array) After Sorting
        System.out.println(" Array After Sorting is: " + Arrays.toString(arr));
    }
    // Method of Selection Sort
    static void selectionSort(int [] arr){
        for(int i=0; i<arr.length; i++){
            // Find the Maximum Index in the Remaining array and Swap with its correct index
            int last = arr.length - i - 1;
            int maxIndex = getMaxIndex(arr, 0, last);
            swap(arr, maxIndex, last);
        }
    }

    static void swap(int [] arr, int a , int b){
        int temp = arr[a];
        arr[a]   = arr[b];
        arr[b]   = temp;
    }

    static int getMaxIndex(int [] arr, int start, int end){
        int max = start;
        for(int i = start; i <= end; i++){
            if(arr[max] < arr[i])
                max = i;
        }
        return max;
    }
}
