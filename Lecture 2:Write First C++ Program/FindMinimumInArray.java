package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class FindMinimumInArray {
    // Find Minimum number in a Given Integer Array
    public static void main(String [] args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take SIZE of the Array as a Input from the USER
        System.out.print(" Enter SIZE of the Array: ");
        int n = sc.nextInt();
        // Declare Array of Required SIZE
        int [] arr = new int[n];
        // Fill the Array by Taking Inputs from the USER
        System.out.print(" Enter " + n + " Elements: ");
        for(int i=0; i<arr.length; i++){
            int element = sc.nextInt();   // Take Input From the USER
            arr[i] = element;             // Store Input in Array
        }
        // Display the Array
        System.out.println(Arrays.toString(arr));
        // Display the Minimum Element in the Array
        System.out.println(" Minimum Element in Array " + Arrays.toString(arr) + " is: " + minimum(arr));
    }

    static int minimum(int [] arr){
        int min = Integer.MAX_VALUE;   // Take Initially minimum Element is MAX_VALUE of Integer
        for (int element : arr) {      // Check for Every Element in Array
            if (element < min)         // if Any Element is less than the initial min value
                min = element;      // Update the min value
        }
        return min;  // return the Minimum Element from the Array
    }
}
