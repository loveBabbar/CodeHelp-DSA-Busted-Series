package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class BinarySearch {
    // Binary Search
    public static void main(String [] args){
        /*
        Binary Search Explanation:
          NOTE :   Binary Search can be Only Applied on Sorted Arrays
              let Array is -->  [1,2,3,4]      key = 4
              here,
                 indices -->   0   1   2   3
                             [ 1,  2,  3,  4 ]
                              /            \
                            start          end
                      mid = start + (end - start)/2  -->  0 + (3-0)/2   --> 3/2  --> 1
             Step1 :   arr[mid]  = arr[1] --> 2    Not Equal to 4 (key)
             Step2 :   arr[mid] > key   -->  2 > 4    FALSE
             Step3 :   arr[mid] < key   -->  2 < 4    TRUE   --> Search in Right Sub Array
                    start --> mid + 1
                    [ 1,  2,  3,  4 ]
      indices -->     0   1   2   3
                              /   \
                            start end
                   Now , mid = 2 + (3-2)/2   --> 2 + 1/2  -->  2 + 0 --> 2
            step1 :  arr[mid] = arr[2] --> 3  Not Equal to 4 (key)
            step2 :  arr[mid] > key    --> 3 > 4   FALSE
            step3 :  arr[mid] < key    --> 3 < 4    TRUE  --> Search in Right SUb Array
               now,   start --> mid + 1
                    [ 1,  2,  3,  4 ]
      indices -->     0   1   2   3
                                 /\
                            start end
                 Hence , mid = 3 + (3-3)/2  --> 3 + 0   --> 3
            step1:  arr[mid] = arr[3] -->  4   YES Equals to 4 (key)   --> return true

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
        if(binarySearch(arr, key))
            System.out.println(key + " is Found in the Array " + Arrays.toString(arr));
        else
            System.out.println(key + " is NOT Found in the Array " + Arrays.toString(arr));
    }
    // Method to check whether Element Exist in the Array or NOT
    static boolean binarySearch(int [] arr, int key){
        // Take two Pointers Start and End
        // Initialize start to 0 and end to arr.length - 1
        int start = 0;
        int end   = arr.length - 1;
        if(arr.length == 0)       // If Array is Empty then return false in that Case
            return false;
        while(start <= end){     // repeat the Following Steps till start <= end
            // Find mid value
            /*
            int mid = (start + end)/2;
            --> Problem with This is that Integers has Fixed SIZE
            --> For Large Integers it might be possible that (start + end)/2 Exceed the Range of the Integers
             */
            int mid = start + (end - start)/2;
            // If Element at mid is Required Element then return true
            if(arr[mid] == key)
                return true;
            else if(arr[mid] > key)    // if mid element is > key then Find left subArray
                end = mid-1;
            else                       // else find in right SubArray
                start = mid+1;
        }

        return false;   // Return false if key not FOUND
    }
}
