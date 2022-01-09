package com.company;

import java.util.Scanner;
import java.util.Arrays;

public class SymmetricMatrix {
    // Check the Symmetric Matrix
    public static void main(String [] args){
        // A Matrix is Said to be a Symmetric Matrix if A = A^T  -->  transpose of A
        // Creating Scanner Object for taking inputs from the USER
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

        // Now Finding Transpose of MATRIX
        int [][] transpose = new int[noOfColumns][noOfRows];
        for(int row = 0; row < matrix.length; row++){
            for(int column = 0; column< matrix[row].length ; column ++){
                transpose[column][row]  = matrix[row][column];
            }
        }

        // Now Check if Matrix and it's transpose are Equal or not
        for(int row = 0; row < matrix.length; row++){
            for(int column = 0; column < matrix[row].length; column++){
                if(matrix[row][column] != transpose[row][column]){
                    System.out.println(" Matrix is not Symmetric ");
                    return ;
                }
            }
        }

        System.out.println(" Matrix is Symmetric ");
    }
}
