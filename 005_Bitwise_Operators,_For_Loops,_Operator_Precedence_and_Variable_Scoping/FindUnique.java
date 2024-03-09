import java.util.Arrays;

public class FindUnique {
    // Find Unique Element in an Array that Appears only once
    public static void main(String [] args){
        int [] arr = {1,2,1,3,4,3,2};
        // Display the unique Element in the Array
        System.out.println(" Unique Element in the Array " + Arrays.toString(arr) + " is: " + unique(arr));
    }

    static int unique(int [] arr){
        int uniqueElement = 0;
        for (int element : arr) uniqueElement ^= element;
        return  uniqueElement;
    }
}
