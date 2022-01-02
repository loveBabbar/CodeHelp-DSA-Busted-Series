package RecursionQues2;

import java.util.ArrayList;

public class FindAllOccurrencesOfTarget {
    // Find All the Occurrences of Target in the Given Array
    public static void main(String [] args){
        int [] arr = {1,2,2,2,3};
        int target = 2;
        findAllOccurrences(arr, target, 0);
        System.out.println(list);
    }

    static ArrayList<Integer> list = new ArrayList<>();
    static void findAllOccurrences(int [] arr, int target, int index){
        if(index == arr.length)
            return;
        if(arr[index] == target)
            list.add(index);
        findAllOccurrences(arr, target, ++index);
    }

}
