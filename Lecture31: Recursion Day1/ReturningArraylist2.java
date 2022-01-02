package RecursionQues2;

import java.util.ArrayList;

public class ReturningArraylist2 {
        // Find All the Occurrences of Target in the Given Array
        public static void main(String [] args){
            int [] arr = {1,2,2,2,3};
            int target = 2;
            System.out.println(findAllOccurrences(arr, target, 0));
        }

        static ArrayList<Integer> findAllOccurrences(int [] arr, int target, int index){
            ArrayList<Integer> list = new ArrayList<>();
            if(index == arr.length)
                return list;
            // this will Contains Answer for that Function call only
            if(arr[index] == target)
                list.add(index);
            ArrayList <Integer> ansFromBelowCalls = findAllOccurrences(arr, target, ++index);
            list.addAll(ansFromBelowCalls);
            return list;
        }

    }
