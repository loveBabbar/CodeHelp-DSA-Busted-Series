package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class MaximumPopulationYear {
    // Maximum Population Year
    public static void main(String[] args) {
        /*
        https://leetcode.com/problems/maximum-population-year/
            Return the earliest year with the maximum population.
            Example 1:

            Input: logs = [[1993,1999],[2000,2010]]
            Output: 1993
            Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
         */
        // creating Scanner Object for taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // taking Size of the 2D Array From the USER
        System.out.print(" Enter Number of Rows and Columns for the 2D Array: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Declaring Array of the Required Size
        int[][] arr = new int[noOfRows][noOfColumns];
        // Now Filling the 2D Array ROW Wise
        System.out.println(" Enter Elements: ");
        for (int[] row : arr) {
            for (int i = 0; i < row.length; i++) {
                row[i] = sc.nextInt();
            }
        }
        // Displaying 2D Array
        for (int[] row : arr) {
            System.out.println(Arrays.toString(row));
        }

        // Now Displaying Year with Maximum
        System.out.println(" Year with Maximum Population is: " + maximumPopulation(arr));

    }

    public static int maximumPopulation(int[][] logs) {
        // Declaring Array of Size 101
        int[] arr = new int[101];  // Initializing of 101 BECAUSE OF Constraint 1950 <= birth i < death i <= 2050
        for (int[] log : logs) {    // For Every row in logs
            for (int j = log[0]; j < log[1]; j++) {   // Range is from [birth i, death i - 1] Both Inclusive
                arr[j - 1950]++;
                /*
                During j = 1950
                arr[1950-1950] = arr[0] will be incremented
                Similarly During j = 1951
                arr[1] will be incremented ..... and so on..
                */
            }
        }
        // System.out.println(Arrays.toString(arr));
        int maxValue = 0;     // Initialize maxValue of Population as 0
        int maxYear = 1950;   // Let Initially YEAR with Maximum Population is 1950
        for (int i = 0; i < arr.length; i++) {   // Now compare maxValue with all the Elements of arr
            if (arr[i] > maxValue) {        // If any Element is Greater than it
                maxValue = arr[i];       // update maxValue
                maxYear = i + 1950;       // Once maxValue is Incremented then Also Increment the year
                /*
                 EXAMPLE
                    Suppose i = 2 has MAX VALUE
                    so YEAR is 2+1950 = 1952
                */
            }
        }
        return maxYear;

    }
}
