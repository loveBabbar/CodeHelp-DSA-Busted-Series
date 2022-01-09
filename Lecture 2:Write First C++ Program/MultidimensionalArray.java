package com.company;

import java.util.Arrays;
class MultidimensionalArray{
    public static void main(String [] args){
        /*
             1 2 3
             4 5 6
             7 8 9

             2D Array is Also Called Matrix
             --> Imagine it as an ARRAY of ARRAYS
             --> Every Index is an Array Itself
             [[1,2,3],    --> 0
              [4,5,6],    --> 1
              [7,8,9]]    --> 2

             REMEMBER:
                   int [][] arr = new int[3][];
                    --> Here Adding the ROW is Mandatory

                    int [][] arr = new int[][3];   --> ERROR !
         */

        int [][] arr = {
                            {1,2,3},
                            {4,5,6},
                            {7,8,9}
                                    };

        // System.out.println(arr.length);

        for(int i=0;i<arr.length ; i++){
            for(int j = 0;j<arr.length;j++){
                System.out.print( " " + arr[i][j]);
            }
            System.out.println();
        }

        for(int i=0;i<arr.length; i++) {
            System.out.println(Arrays.toString(arr[i]));
        }

        System.out.println(Arrays.toString(arr));   // --> It will Print the References
    }
}
