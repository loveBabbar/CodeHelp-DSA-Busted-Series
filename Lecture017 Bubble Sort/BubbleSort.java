

import java.util.Scanner;
import java.util.Arrays;
public class BubbleSort {
    // Bubble Sort -> Also Known as Sinking Sort and Exchange Sort
    public static void main(String [] args){
        /*
         */

        // Creating Scanner Object for taking inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take the SIZE of 1D Array from the USER
        System.out.print(" Enter SIZE of 1D Array: ");
        int n = sc.nextInt();
        // Create Array of Required SIZE
        int [] arr = new int[n];
        //Fill the Array by taking n Inputs from the USER
        System.out.print(" Enter " + n + " Elements: ");
        for(int i=0; i<arr.length; i++)
            arr[i] = sc.nextInt();
        // Display Array Before Sorting
        System.out.println(" Array Before Sorting is: " + Arrays.toString(arr));
        // Apply Bubble Sort on the Given Array
        bubbleSort(arr);
        // Display Array After Sorting
        System.out.println(" Array After Sorting is: " + Arrays.toString(arr));
    }
    // Method of Bubble Sort
    static void bubbleSort(int [] arr){
        for(int i=0; i<arr.length-1 ; i++){
            boolean isSorted = true;
            for(int j = 0; j<arr.length-i-1; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    isSorted = false;
                }
            }
            if(isSorted)
                break;

        }
    }
}
