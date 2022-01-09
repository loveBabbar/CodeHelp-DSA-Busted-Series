package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class SearchInStrictlySortedArray {
    // Search in Strictly Sorted Array
    public static void main(String [] args){
        /*
        Strictly Sorted Array is Like
        [ 1,  2,  3, 4 ]
        [ 5,  6,  7, 8 ]
        [ 9, 10, 11, 12]
         */
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take the SIZE of Strictly Sorted Array from the USER
        System.out.print(" Enter Number of Rows and Columns of Strictly Sorted Array: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Crating Array of Required SIZE
        int [][] arr = new int[noOfRows][noOfColumns];
        // Fill Array Elements in Strictly Sorted Order
        System.out.print(" Enter Elements ROW wise: ");
        for(int []row: arr){
            for(int i=0; i<row.length; i++)
                row[i] = sc.nextInt();
        }
        // Display the Array
        for(int [] row: arr)
            System.out.println(Arrays.toString(row));
        // Now take the Target Element from the USER
        System.out.print(" Enter Target Element to Find: ");
        int target = sc.nextInt();
        // Display target Element Found or NOT
        System.out.println(target + " Found in the Given Array at Index " + Arrays.toString(search(arr, target)));
    }

    static int [] search(int [][] matrix, int target){
        int row = matrix.length;
        int col= matrix[0].length;

        if(row == 1)
            return binarySearch(matrix, row, 0, col-1, target);
        // run the Loop till Two Rows wil be remaining
        int rStart = 0;
        int rEnd  = row -1;
        int cMid = col/2;
        while(rStart < (rEnd-1)){ // While it will True it will have more than Two ROWS
            int mid = rStart + (rEnd - rStart)/2;
            if(matrix[mid][cMid] == target)
                return new int[]{mid, cMid};
            if(matrix[mid][cMid] < target)
                rStart = mid;
            else
                rEnd = mid;
        }
        // Now we have 2 Rows
        // check whether the Target is in Column of 2 Rows
        if(matrix[rStart][cMid] == target)
            return new int[]{rStart, cMid};
        if(matrix[rStart + 1][cMid] == target)
            return new int[]{rStart+1, cMid};

        // Search in first Half
        if(target <= matrix[rStart][cMid -1 ]){
            return binarySearch(matrix, rStart, 0, cMid-1, target);
        }
        // Search in Second Half
        if(target >= matrix[rStart][cMid + 1 ] && target <= matrix[rStart][col - 1 ] ){
            return binarySearch(matrix, rStart, cMid +1 , col-1, target);
        }
        // Search in third Half
        if(target <= matrix[rStart +1 ][cMid -1 ]){
            return binarySearch(matrix, rStart + 1, 0 , cMid -1, target);
        }
        else{
            return binarySearch(matrix, rStart+1 , cMid +1 , col-1, target);
        }
    }
    // search in the Row provided and Column Provided
    static int [] binarySearch(int [][] matrix, int row, int cStart, int cEnd, int target){
        while(cStart <= cEnd) {
            int mid = cStart + (cEnd - cStart) / 2;
            if (matrix[row][mid] == target)
                return new int[]{row, mid};
            if(matrix [row][mid] > target)
                cEnd = mid-1;
            else
                cStart = mid+1;
        }
        return new int[]{-1, -1};
    }
}
