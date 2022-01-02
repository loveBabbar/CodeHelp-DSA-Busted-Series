package RecursionQues2;

import java.util.ArrayList;

public class ReturningArrayList {
    // Find All the Occurrences of Target in the Given Array
    public static void main(String [] args){
        int [] arr = {1,2,2,2,3};
        int target = 2;
        ArrayList<Integer> list = new ArrayList<>();
        System.out.println(findAllOccurrences(arr, target, 0, list));
    }

    static ArrayList<Integer> findAllOccurrences(int [] arr, int target, int index, ArrayList<Integer> list){
        if(index == arr.length)
            return list;
        if(arr[index] == target)
            list.add(index);
        return findAllOccurrences(arr, target, ++index, list);
    }

}
