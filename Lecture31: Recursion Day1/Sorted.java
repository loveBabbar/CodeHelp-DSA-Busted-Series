package RecursionQues2;

public class Sorted {
    // Check whether an Array is Sorted or Not
    public static void main(String [] args){
        int [] arr = {1,2,4,3};
        System.out.println(sorted(arr, 0));
    }

    static boolean sorted(int [] arr, int index){
        if(index == arr.length - 1)
            return true;

       return (arr[index] < arr[index +1] && sorted(arr, ++index));
    }
}
