package BitManipulation;

import java.util.Arrays;

public class FlipAnImage {
    // flip the Image
    public static void main(String [] args){
        // Create an Array
        int [][] arr = {{1, 1, 0},
                        {1, 0, 1},
                        {0, 0, 0}};
        // Display Array Before Flip
        for(int [] row: arr)
            System.out.println(Arrays.toString(row));
        // Function that Flip the Array
        flipAndInvertImage(arr);
        // Display Array After Flip
        for(int [] row: arr)
            System.out.println(Arrays.toString(row));
    }

    static void flipAndInvertImage(int [][] image){
        for(int [] row: image){
            for(int i=0; i < (image[0].length + 1)/2; i++){
                int temp = row[i] ^ 1;
                row[i] = row[image[0].length - 1 - i] ^ 1;
                row[image[0].length - 1 - i] = temp;
            }
        }
    }
}
