package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class SumOfLowerTriangularMatrix {
    // Find Sum of Lower Triangular Matrix
    public static void main(String [] args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of Rows and Columns of Matrix
        System.out.print(" Enter Number of ROWS and COLUMNS of the Matrices: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Creating Matrix of Required SIZE
        int[][] matrix = new int[noOfRows][noOfColumns];
        // Take Elements of Matrix
        System.out.println(" Enter Elements of Matrix Row Wise ");
        for (int[] row : matrix) {
            for (int i = 0; i < row.length; i++)
                row[i] = sc.nextInt();
        }
        // Displaying the Matrix
        for (int[] row : matrix)
            System.out.println(Arrays.toString(row));

        System.out.println(" Lower triangular Matrix is ");
        // Display Lower triangular Matrix
        // Also Find the SUM
        int sum = 0;
        for(int row=0; row< matrix.length; row++){
            for(int column = 0; column < matrix[row].length; column++){
                if(row >= column) {
                    System.out.print(matrix[row][column] + " ");
                    sum += matrix[row][column];
                }
                else
                    System.out.print(0 + " ");
            }
            System.out.println();
        }
        // Display the Sum of Lower Triangular Matrix
        System.out.println(" Sum of Lower triangular Matrix is: " + sum);
    }
}
