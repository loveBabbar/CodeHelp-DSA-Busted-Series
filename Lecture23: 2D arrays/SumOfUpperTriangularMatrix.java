package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class SumOfUpperTriangularMatrix {
    // Sum of Upper Triangular of Matrix
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

        System.out.println(" Upper triangular Matrix is ");
        // Display Upper triangular Matrix
        // And Also Calculate SUM
        int sum = 0;
        for(int row=0; row< matrix.length; row++){
            for(int column = 0; column < matrix[row].length; column++){
                if(column >= row) {
                    System.out.print(matrix[row][column] + " ");
                    sum += matrix[row][column];
                }
                else
                    System.out.print(0 + " ");
            }
            System.out.println();
        }
        // Display Sum of Upper triangular Matrix
        System.out.println(" Sum of Upper Triangular Matrix is: " + sum);
    }
}
