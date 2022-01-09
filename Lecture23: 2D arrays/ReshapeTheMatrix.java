package com.company;

import java.util.*;
public class ReshapeTheMatrix {
    // Reshape the Matrix
    public static void main(String [] args){
        /*
        https://leetcode.com/problems/reshape-the-matrix/
         */
        // creating Scanner Object for Taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // take size of the Given matrix from the USER
        System.out.print(" Enter Number of Rows and Columns for the Given Matrix: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Declare Array of Required SIZE
        int [][] matrix = new int[noOfRows][noOfColumns];

        // Fill the Array
        System.out.print(" Enter Elements ROW Wise: ");
        for(int [] row: matrix){
            for(int i=0 ; i<row.length; i++)
                row[i] = sc.nextInt();
        }
        // Display the Array
        for(int [] row: matrix){
            System.out.println(Arrays.toString(row));
        }
        // Now Take the Size of the Reshaped Matrix from the USER
        System.out.print(" Enter ROWS and COLUMNS for the Reshaped Matrix: ");
        int r = sc.nextInt();
        int c = sc.nextInt();

        // display the Resultant Matrix
        for(int [] row:matrixReshape(matrix , r, c)){
            System.out.println(Arrays.toString(row));
        }
    }

    public static int[][] matrixReshape(int[][] mat, int r, int c) {
        /*
        EXPLANATION:
             Let
             m --> No of ROWS of mat Matrix
             n --> No of COLUMNS of mat Matrix
             Check is the Number of Elements in the Both the Matrices that is mat and resultant matrix are Equal or not
             i.e m*n == r*c ?
             if YES then RESHAPE the MATRIX
             if NO then return the Original MATRIX

             Procedure for reshaping the Matrix
             1. Firstly, Store all the Elements of Given 2D Matrix into a List
             2. then Fill the Resultant Matrix using that List
             3. At last Return the Resultant Matrix
         */

        // Check is the elements in both the Matrix are same or Not?
        if (r * c == mat.length * mat[0].length) {
            // Declare the List
            List<Integer> list = new ArrayList<>();
            // Declaring Reshaped Matrix --> Resultant Matrix
            int[][] reshapedMatrix = new int[r][c];
            // Now Store all the Elements of the Matrix into the List
            for (int[] row : mat) {    // For Each ROW
                for (int element : row) {
                    list.add(element);    // Store the Elements in the List
                }
            }

            // Now Iterate over the Reshaped Matrix and Fill it Using List
            int i = 0;  // Counter for iterating Over the List
            for (int row = 0; row < r; row++) {   // For Every ROW
                for (int column = 0; column < c; column++) {  // For Each Column
                    reshapedMatrix[row][column] = list.get(i);  // Fill the Elements using list
                    i++;  // Increment the Counter of List
                }
            }
            // After the Reshaped Matrix is Ready then Return it
            return reshapedMatrix;
        }
        // If Elements are not Equal then return the Original List
            return mat;
    }
}
