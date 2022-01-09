package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class NumbersWithEvenNumberOfDigits {
    // Find Numbers with Even Number of Digits
    public static void main(String [] args){
        /*
        https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
         */
        // Creating Scanner Object for taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // Take SIZE of the Array as a Input From the USER
        System.out.print(" Enter SIZE of the Array: ");
        int n = sc.nextInt();
        // Create Array of Required SIZE
        int [] arr = new int[n];
        // Fill the Array
        System.out.print(" Enter " + n + " Elements: ");
        for(int i=0; i<arr.length; i++){
            arr[i] = sc.nextInt();
        }
        // Display the Array
        System.out.println(Arrays.toString(arr));
        // Display Count of numbers with Even Number of Digits
        System.out.println(" Count of Elements with Even Number of Digits: " + findNumbers3(arr));
    }
    public static int findNumbers(int[] nums) {
        int numberCount = 0; // Let Initially there is no Number with Even Number of Digits
        for(int element: nums){   // For Every Element in Array nums
            if(evenDigits(element))  // Check is the Number contains Even Number of Digits or Not?
                numberCount++;      // If YES then Increment the Count of Numbers Contains Even Number of Digits
        }
        // Return the Total Numbers that Contains Even Number of Digits
        return numberCount;
    }
    static boolean evenDigits(int n){
        // Let Initially Number of Digits in the Number is 0
        int digitCount = 0;
        while(n>0){
            // Increment the digitCount
            digitCount++;
            n /= 10;
        }
        // return true if Digit Count is EVEN or false if Digit Count is ODD
        return (digitCount % 2 == 0);
    }

    // Approach 2
    public static int findNumbers2(int [] nums){
        int count = 0;
        for(int element: nums){
            if((int)(Math.log10(element)) + 1 % 2 == 0 )
                count++;
        }
        return count;
    }

    // Approach 3
    public static int findNumbers3(int [] nums){
        int count = 0;
        for(int num: nums){
            String number = num + "";
            if(number.length() % 2 == 0)
                count ++;
        }
        return count;
    }
}
