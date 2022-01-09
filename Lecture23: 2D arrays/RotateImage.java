package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class RotateImage {
    //Rotate Image
    public static void main(String [] args){
        /*
        https://leetcode.com/problems/rotate-image/
        You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
        You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
        DO NOT allocate another 2D matrix and do the rotation.

        Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [[7,4,1],[8,5,2],[9,6,3]]
         */

        // Creating Scanner Object For Taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // Take the Size of the 2D array From the USER
        System.out.print(" Enter Number of ROWS and COLUMNS for 2D Array: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Declare the 2D array of Required SIZE
        int [][] matrix = new int[noOfRows][noOfColumns];

        // Fill The Array Row WISE
        System.out.println(" Enter Elements ROW Wise: ");
        for(int [] row: matrix){
            for(int i=0;i<row.length; i++){
                row[i] = sc.nextInt();
            }
        }
        // Display the 2D Array
        for(int []row: matrix){
            System.out.println(Arrays.toString(row));
        }

        // Calling the Rotate Method
        rotate(matrix);

        // Now Display the Resultant 90 Degree Rotated Array
        System.out.println(" Rotated Matrix is: ");
        for(int [] row: matrix){
            System.out.println(Arrays.toString(row));
        }

    }

    public static void rotate(int[][] matrix) {
        // To Rotate Matrix 90 Degree there are two Simple Steps
        /*
            STEP1 : FIND the TRANSPOSE (Ri --> Ci) of the Matrix
            STEP2 : FLIP the ELEMENTS
        */

        // Step1: Transpose
        for(int row = 0;row < matrix.length; row++){
            for(int column = 0 ; column <row; column++){
                // INTERCHANGE the row ELEMENTS with COLUMN
                int temp = matrix[row][column];
                matrix[row][column] = matrix[column][row];
                matrix[column][row] = temp;
            }
        }

//         for(int[] row: matrix){
//             System.out.println(" Transpose: "+ Arrays.toString(row));
//         }

        // At this point we have TRANSPOSE of the Matrix
        // STEP2 : NOW Flip the ELEMENTS of ROW
        /*

     Original Matrix          Transpose        Now FLIP THE Elements of EACH ROW

                             start    end
                                \     /
        1   2  3       0 -->    1  4  7     flip 1 with 7      7  4  1
        4   5  6       1 -->    2  5  8     flip 2 with 8      8  5  2
        7   8  9       2 -->    3  6  9     flip 3 with 9      9  6  3


        */

        int start = 0; // Take start pointer and points to 0
        int end   = matrix.length -1 ; // Take End pointer and points to n-1 index i.e Last Index of ROW

        // FLIP the Elements till START <= END
        while(start <= end){
            // Flip for EACH ROW
            // Use For LOOP
            for(int row = 0; row < matrix.length ; row++){
                // Swap/ Flip the Elements of Start and End
                int temp           = matrix[row][start];
                matrix[row][start] = matrix[row][end];
                matrix[row][end]   = temp;
            }

            // Now Increment the START
            start ++;
            // And Decrement the END
            end--;
        }
    }
//    ANALYSIS :
//    TIME COMPLEXITY --> O(m*n) = O(M)
//    SPACE COMPLEXITY --> O(1) --> CONSTANT

}