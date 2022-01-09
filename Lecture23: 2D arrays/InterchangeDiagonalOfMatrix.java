package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class InterchangeDiagonalOfMatrix {
    // Interchange Diagonals of a Matrix
    public static void main(String [] args) {
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

        // Swap Elements of the Diagonal Elements
        for(int i=0; i < matrix.length; i++){
            if(i != matrix.length/2){
                int temp = matrix[i][i];
                matrix[i][i] = matrix[i][matrix.length - i - 1];
                matrix[i][matrix.length -i - 1] = temp;
            }
        }

        System.out.println(" Matrix After Interchanging Diagonal Elements");
        for(int []row : matrix){
            System.out.println(Arrays.toString(row));
        }
    }
}
