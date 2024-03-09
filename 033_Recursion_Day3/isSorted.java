public class isSorted {
    public static void main(String[] args) {

        int[] arr = {2 ,4 ,15 ,15 ,15};
        boolean  ans = checkSorted(arr , 5);
        if(ans)
            System.out.println("Array is Sorted");
        else
            System.out.println("Array is unsorted");
    }

    public static boolean checkSorted(int[] arr , int size){
        if(size <=1) return true;
        return sortedHelper(arr , 1 , size);
    }

    //created this helper method as in Java we cannot do(arr + 1) (Java does not allow us to play with pointers)
    // Java allows us to create references but at backend it uses concept of pointers.

    //we have passed the index value and if condition is satisfied we increase idx + 1;

    public static boolean sortedHelper(int[] arr , int idx , int size){
        //base case
        if(idx == size)
            return true;

        //case to check previous element is greater than current element
        if(arr[idx - 1] > arr[idx])
            return false;
        return sortedHelper(arr , idx + 1 , size); // if reached till here we have to check for remaining element
    }
}
