package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class MatrixDiagonalSum {
    //  Matrix Diagonal Sum
    public static void main(String [] args){
        /*
        https://leetcode.com/problems/matrix-diagonal-sum/
        */
        // Scanner Object for Taking Input from the USER
        Scanner sc = new Scanner(System.in);

        // taking Size of Array from the USER
        System.out.print(" Enter Number of ROWS and COLUMNS: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Now Creating Array of Required SIZE
        int [][] arr = new int[noOfRows][noOfColumns];
        // Now Taking Elements from the USER
        for(int[] rows: arr){
            for(int i=0;i< rows.length;i++){
                rows[i] = sc.nextInt();
            }
        }
        // Displaying 2D Array arr
        for(int [] row: arr) {
            System.out.println(" Array is: " + Arrays.toString(row));
        }

        // Passing Array to Function for Calculating Diagonal SUM
        System.out.println(" Diagonal SUM is: " + diagonalSum(arr));

    }
    public static int diagonalSum(int[][] mat) {
       int sum = 0;  // Initially Sum is 0
       int i=0;     // i --> Counter for Primary DIAGONAL
       int k = mat.length-1;   // k --> Counter for Secondary DIAGONAL
       while(i< mat.length && k>=0){     // PrimaryDiagonal Must be less than length of Array and Secondary Diagonal > 0
           // Now update Sum BY Adding Primary Diagonal Value and Secondary Diagonal Value
           sum += mat[i][i] + mat[i][k];
           // Now Subtracting Value that Occurs Twice in SUM i.e when Primary Diagonal == Secondary Diagonal
           if(i==k){
               // We areSubtracting this Value Because it was Added in the SUM variable TWICE
               sum -= mat[i][i];
           }
           i++;    // Increment Counter of Primary Diagonal
           k--;   // Decrement Counter of Secondary Diagonal
       }
       // After Calculating SUM Return the SUM
       return sum;
    }
}
