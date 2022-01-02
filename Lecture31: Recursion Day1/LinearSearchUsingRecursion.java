package RecursionQues2;

import java.util.Arrays;

public class LinearSearchUsingRecursion {
    // Linear Search Using recursion
    public static void main(String [] args){
        int [] arr = {1,2,3,4,2,35,66};
        int target = 35;
        if(found(arr, target, 0))
            System.out.println(target + " Found in the Array " + Arrays.toString(arr));
        else
            System.out.println(target + " is NOT Found in the Array " + Arrays.toString(arr));
    }

    static boolean found(int [] arr, int target, int index){
        if(index == arr.length)
            return false;
        if(arr[index] == target)
            return true;
        return  found(arr, target, ++index);
    }


/*
    static boolean found2(int [] arr, int target, int index){
        if(index == arr.length)
            return false;
        return  arr[index] == target || found(arr, target, ++index);
    }
*/

}
