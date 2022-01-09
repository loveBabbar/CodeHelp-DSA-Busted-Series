package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class RichestCustomerWealth {
    // Richest Customer Wealth
    public static void main(String [] args){
        /*
        https://leetcode.com/problems/richest-customer-wealth/

        Input: accounts = [[1,2,3],[3,2,1]]
        Output: 6
        Explanation:
        1st customer has wealth = 1 + 2 + 3 = 6
        2nd customer has wealth = 3 + 2 + 1 = 6
        Both customers are considered the richest with a wealth of 6 each, so return 6.
         */

        // Creating Scanner Object For Taking Input From the User
        Scanner sc = new Scanner(System.in);

        // taking Number of Rows and Columns from the User
        System.out.print(" Enter Number of ROWS and COLUMNS: ");
        int row = sc.nextInt();
        int column = sc.nextInt();

        // Declaring Array with Required Size
        int [][] arr = new int [row][column];

        // Taking Elements from the User
        for(int i = 0;i < arr.length ; i++){
            for(int j=0; j < arr[i].length ; j++){
                System.out.print(" Enter " + " [" + i + "] " + "[" + j + "] ");
                arr[i][j] = sc.nextInt();
            }
        }

        // Displaying 2D array on the Screen
        for(int [] rows: arr) {
            System.out.println(Arrays.toString(rows));
        }

        int maxValue = maximumWealth(arr);
        System.out.println(" Maximum Wealth is: " + maxValue );

    }

    public static int maximumWealth(int[][] accounts) {
        // Creating New Array SUM for Storing SUM OF ROWS or 2D Array
        int [] sum = new int[accounts.length];
        int index = 0;
        for (int[] account : accounts) {       // Enhanced For Loop
            int sumOfRow = 0;

            for (int i = 0; i < account.length; i++) {

                sumOfRow += account[i];

            }
            // Storing Sum of ROWS in the 1D Array Sum
            sum[index] = sumOfRow;
            index++;
        }

        // System.out.println(Arrays.toString(sum));
        // Finding the Largest Element in 1D Array that Contains Sum of Rows of 2D Array
        int max = sum[0];
        for (int j : sum) {   // --> Enhanced for Loop
            if (j > max)
                max = j;
        }

        // After Finding the Maximum Element
        // Return the Max Element
        return max;
    }
}
