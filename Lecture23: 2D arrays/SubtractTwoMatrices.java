package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class SubtractTwoMatrices {
    // Subtract Two Matrices
    public static void main(String [] args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of Rows and Columns of Matrix
        System.out.print(" Enter Number of ROWS and COLUMNS of the Matrices: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Creating two Matrices of Required SIZE
        int [][] matrixA = new int[noOfRows][noOfColumns];
        int [][] matrixB = new int[noOfRows][noOfColumns];
        // Take Elements of First Matrix
        System.out.println(" Enter Elements of First Matrix Row Wise ");
        for(int [] row : matrixA){
            for(int i=0; i<row.length; i++)
                row[i] = sc.nextInt();
        }
        System.out.println(" Enter Elements of Second Matrix Row Wise ");
        for(int [] row : matrixB){
            for(int i=0; i<row.length; i++)
                row[i] = sc.nextInt();
        }

        // Calculating Subtraction of Both the MATRICES
        int [][] sub = new int[noOfRows][noOfColumns];
        for(int row = 0; row<sub.length; row++){
            for(int column=0; column<sub[row].length ; column++){
                sub[row][column] = matrixA[row][column] - matrixB[row][column];
            }
        }
        // Display the Resultant Matrix
        for(int [] row : sub){
            System.out.println(Arrays.toString(row));
        }
    }
}
