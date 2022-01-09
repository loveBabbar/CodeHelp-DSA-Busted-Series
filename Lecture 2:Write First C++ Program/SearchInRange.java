package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class SearchInRange {
    // Search in Array within a given Range
    public static void main(String [] args){
        // Creating Scanner Object For Taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take SIZE of Array from the USER
        System.out.print(" Enter Size of the Array: ");
        int n = sc.nextInt();
        // Declare the Array of Required SIZE
        int [] arr = new int[n];
        // Fill the Array By taking Inputs from the USER
        System.out.print(" Enter " + n + " Elements: ");
        for(int i=0; i< arr.length ; i++){
            int element = sc.nextInt();  // Take Element from the USER
            arr[i] = element;     // Store Element in the Array
        }
        // Display the Array with it's Index Values
        System.out.print(" Indices --> ");
        for(int i=0 ; i<arr.length ; i++){
            System.out.print(" " + i + " ");
        }
        System.out.println();
        System.out.println(" Array   --> " + Arrays.toString(arr));   // Display the Array

        // Take Range of Indices for Search
        System.out.print(" Enter Range for Search (start and End): ");
        int start = sc.nextInt();
        int end = sc.nextInt();
        // Take Element to Search
        System.out.print(" Enter Element to Search: ");
        int key = sc.nextInt();

        if(keyFound(arr, key, start, end))
            System.out.println(key + " Found in Array in range " + start + " to " + end);
        else
            System.out.println(key + " NOT Found in Array in range " + start + " to " + end);
    }

    static boolean keyFound(int [] arr, int key, int start, int end){
        for(int i= start;  i<= end; i++){        // Search in the Given Range
            if(key == arr[i])                    // check for Every Element
                return true;                    // If Element Found return true
        }
        return false;                          // If Element NOT found return false
    }
}
