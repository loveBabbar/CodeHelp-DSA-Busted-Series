package RecursionQues2;

import java.util.Arrays;

public class LinearSearch2 {
    // Linear Search Using recursion start Searching From Last Index
    public static void main(String [] args){
        int [] arr = {1,2,3,4,2,35,66};
        int target = 35;
        if(found(arr, target, arr.length - 1))
            System.out.println(target + " Found in the Array " + Arrays.toString(arr));
        else
            System.out.println(target + " is NOT Found in the Array " + Arrays.toString(arr));
    }

    static boolean found(int [] arr, int target, int index){
        if(index == -1)
            return false;
        if(arr[index] == target)
            return true;
        return  found(arr, target, --index);
    }
}
