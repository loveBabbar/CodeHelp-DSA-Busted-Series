package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class SumOfArrayElements {
    // Print SUM of All Array Elements
    public static void main(String [] args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take SIZE of the Array from the USER
        System.out.print(" Enter SIZE of the ARRAY: ");
        int n = sc.nextInt();
        // Create Array of Required SIZE
        int [] arr = new int[n];
        // Fill the Array with n Elements
        System.out.print(" Enter " + n + " Elements: ");
        for(int i=0; i<n; i++)
            arr[i] = sc.nextInt();
        // Display the Array
        System.out.println(Arrays.toString(arr));
        // Procedure of SUMMATION of Array Elements
        int sum = 0;
        for(int element: arr)
            sum += element;
        // Display the SUM
        System.out.println(" SUM of Array Elements are: " + sum);
    }
}
