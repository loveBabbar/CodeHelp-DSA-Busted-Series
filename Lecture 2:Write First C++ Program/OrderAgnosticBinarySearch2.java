package com.company;

import java.util.Arrays;
import java.util.Scanner;
public class OrderAgnosticBinarySearch2 {
    public static void main(String [] args){
    /*
        Order Agnostic Binary Search:
        --> When we Don't know that Array is sorted in Ascending or Descending Order
        --> In that Case we First Compare First and last Element of the Array
        --> if arr[start] < arr[end]
               --> It means Array is Sorted in Ascending Order
        --> Else  (i.e arr[start] > arr[end])
               --> Array is Sorted in Decreasing Order
         */
    // Creating Scanner Object for taking inputs from the USER
    Scanner sc = new Scanner(System.in);
    // Take SIZE of 1D array from the USER
    System.out.print(" Enter SIZE of the ARRAY: ");
    int n = sc.nextInt();
    // Declare 1D Array of Required SIZE
    int [] arr = new int[n];
    // Fill the 1D Array by taking Inputs from the USER
        System.out.print(" Enter " + n + " Elements: ");
        for(int i=0; i<arr.length; i++) {
        arr[i] = sc.nextInt();
    }
    // Displaying the Array
    System.out.println(Arrays.toString(arr));
    // Take key Element to Search in the ARRAY
    System.out.print(" Enter Element that you want to Search in the Given Array: ");
    int key = sc.nextInt();
    // Display the Result
    // if Element Found --> Print Element is Found
    // else --> Element not Found
    if(orderAgnosticBS(arr, key))
        System.out.println(key + " is Found in the Array " + Arrays.toString(arr));
    else
        System.out.println(key + " is NOT Found in the Array " + Arrays.toString(arr));
}
    static boolean orderAgnosticBS(int [] arr, int key) {
        // Take two Pointers Start and End
        // Initialize start to 0 and end to arr.length - 1
        int start = 0;
        int end   = arr.length - 1;
        if(arr.length == 0)       // If Array is Empty then return false in that Case
            return false;
        // Check whether the Array is Sorted in Ascending or Descending Order
        // isAsc will give true if Array is Ascending Order Sorted
        // else false
        boolean isAsc = arr[start] < arr[end];
        while(start <= end){     // repeat the Following Steps till start <= end
            // Find mid value
            /*
            int mid = (start + end)/2;
            --> Problem with This is that Integers has Fixed SIZE
            --> For Large Integers it might be possible that (start + end)/2 Exceed the Range of the Integers
             */
            int mid = start + (end - start)/2;
            // If Element at mid is Required Element then return true
            // This Condition is Same for both the Cases when Sorted in Ascending or Descending
            if(arr[mid] == key)
                return true;
            if(isAsc) {     // Apply this When Sorted in Ascending Order
                if (arr[mid] > key)    // if mid element is > key then Find left subArray
                    end = mid - 1;
                else                       // else find in right SubArray
                    start = mid + 1;
            } else{        // Apply this When Sorted in Descending Order Sorted
                if (arr[mid] > key)    // if mid element is > key then Find Right subArray
                    start = mid + 1;
                else                       // else find in Left SubArray
                    end = mid - 1;
            }
        }
        return false;   // Return false if key not FOUND
    }
}
