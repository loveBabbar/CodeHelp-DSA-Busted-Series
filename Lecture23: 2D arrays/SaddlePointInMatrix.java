package com.company;

import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class SaddlePointInMatrix {
    // Saddle Point In Matrix
    public static void main(String[] args) {
        /*
            https://leetcode.com/problems/lucky-numbers-in-a-matrix/
      Lucky Numbers in a Matrix --> Also Called Saddle Point
       A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
             Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
             Output: [15]
             Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
     */
        // creating Scanner Object for taking Input From the USER
        Scanner sc = new Scanner(System.in);
        // taking Size of 2D Array from the USER
        System.out.print(" Enter ROWS and COLUMNS of the Array: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Now Declare the 2D Array of Required Size
        int[][] arr = new int[noOfRows][noOfColumns];
        // Now Filling the 2D Array ROW Wise
        System.out.print(" Enter Elements ROW wise: ");
        for (int[] row : arr) {
            // For the First ROW Enter Elements
            for (int i = 0; i < row.length; i++) {
                row[i] = sc.nextInt();
            }
        }
        // Display the 2D Array
        for (int[] row : arr) {
            System.out.println(Arrays.toString(row));
        }

        // Display the Saddle Point
        System.out.println(" Saddle Point (Lucky Number) is: " + luckyNumbers(arr));

    }

    public static List<Integer> luckyNumbers(int[][] matrix) {
        List<Integer> luckyNumber = new ArrayList<>();
        List<Integer> minimumInRow = new ArrayList<>();
        List<Integer> maximumInColumn = new ArrayList<>();
//        for(int []row: matrix){
//            int min = row[0];
//            for (int j : row) {
//                if (j < min)
//                    min = j;
//            }
//            minimumInRow.add(min);
//        }

        for(int row = 0;row<matrix.length ; row++){
            int min = matrix[row][0];
            int max = matrix[row][0];
            for(int column = 0 ; column < matrix[row].length;column ++) {
                if (matrix[row][column] < min)
                    min = matrix[row][column];

                int i =0;
                while(i<matrix.length) {
                    if (matrix[i][column] > max)
                        max = matrix[i][column];
                    if(i == matrix.length-1) {
                        maximumInColumn.add(max);
                    }
                    i++;
                }
            }

            minimumInRow.add(min);
            System.out.println(minimumInRow);
            System.out.println(maximumInColumn);
        }

        // Now Check is Any Element in Both the array List Exist or not?
        for(int i=0;i<matrix.length;i++) {
            if(minimumInRow.contains(maximumInColumn.get(i)))
                luckyNumber.add(maximumInColumn.get(i));
        }
        return luckyNumber;
    }
}
