package com.company;

import java.util.Scanner;
import java.util.Arrays;

public class DetermineWhetherMatrixCanBeObtainedByRotation {
    // Determine Whether Matrix Can Be Obtained By Rotation
    public static void main(String[] args) {
        /*
        https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
         */

        // Create Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);

        // Take the Size of 2D Array ( MATRIX ) From the USER
        System.out.print(" Enter Number of ROWS and COLUMNS of the 2D Matrix: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();

        // Now Declare the 2D Array of Required SIZE
        int[][] mat = new int[noOfRows][noOfColumns];
        // Now Fill the Array
        System.out.print(" Enter Elements ROW Wise: ");
        for (int[] row : mat) {
            for (int i = 0; i < row.length; i++) {
                row[i] = sc.nextInt();
            }
        }
        // Now Display the Matrix i.e 2D Array
        for (int[] row : mat) {
            System.out.println(Arrays.toString(row));
        }

        //Target Matrix is:
        int[][] target = {{1, 1,1},
                          {0,1, 0},
                          {0, 0, 0}};

        // Display the Result
        // That is Can be Obtain the Target MATRIX by Rotating it 90 Degree
        System.out.println(" Result is: " + findRotation(mat, target));
    }

    public static boolean findRotation(int[][] mat, int[][] target) {
        for (int i = 0; i < 4; i++) {
            if (checkEquality(mat, target)) {
                return true;
            }
            rotateMatrix(mat);
        }
        return false;
    }

    public static void rotateMatrix(int [][] mat){
        /*
        To Rotate the MATRIX
          --> Firstly transpose it
          --> then Flip the Elements of ROWS
         */
        for(int row=0; row< mat.length ; row++){
            for(int column=0;column<row ; column++){
                // Interchange ROWS and COLUMNS
                int temp = mat[row][column];
                mat[row][column] = mat[column][row];
                mat[column][row] = temp;
            }
        }

        // At This Point we have Transpose MATRIX
        // NOW FLIP the ELEMENTS of ROWS
        int start = 0;
        int end = mat.length-1;
        while(start <= end) {
            for(int i= 0 ; i< mat.length;i++){
                int temp = mat[i][start];
                mat[i][start] = mat[i][end];
                mat[i][end] = temp;
            }
            start++;
            end--;
        }
    }

    public static boolean checkEquality(int[][] mat, int[][] target) {
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat.length; j++) {
                if (mat[i][j] != target[i][j])
                    return false;
            }
        }
        return true;
    }
}
