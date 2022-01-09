package com.company;

import java.util.Arrays;
public class FlippingAnImage {
    //  Flipping an Image
    public static void main(String [] args){

        // 2D Binary Array image
        int [][] image = {{1,1,0,0},
                          {1,0,0,1},
                          {0,1,1,1},
                          {1,0,1,0}};

        // Displaying Binary Array Image
        for(int[] row: image) {
            System.out.println(" 2D Binary Array Image is: " + Arrays.toString(row));
        }
        // Resultant Array
        int [][] resultantArray = flipAndInvertImage(image);
        for(int[] rowS: resultantArray) {
            System.out.println(" Flipped Image is: " + Arrays.toString(rowS));
        }
    }
    public static int[][] flipAndInvertImage(int[][] image) {
        /*
        To Solve this Problem
        First we have to Reverse Each Row
        and Then Invert Each Element
         */
        for(int row = 0;row<image.length ; row++){
                int start = 0;
                int end = image[row].length-1;
                while(start <= end){
                    int temp = image[row][start];
                    image[row][start] = image[row][end];
                    image[row][end] = temp;
                    start ++;
                    end --;
                }
        }

        for(int [] row:image){
            for(int i = 0; i<row.length;i++) {
                row[i] =row[i]^1;      // ^ --> XOR
                // As we Know       A^1 =  A'  (Complement of A)
            }
        }
        return image;
    }
}
