package RecursionQues2;

public class RotatedBinarySearch {
    // Rotated Binary search using recursion
    public static void main(String [] args){
        int [] arr = {5, 6, 7, 8, 9, 1, 2, 3};
        int target = 7; // ?
        System.out.println(search(arr, target, 0, arr.length - 1));
    }

    static int search(int [] arr, int target, int start, int end){
        if(start > end)
            return -1;

        int mid = start + (end - start)/2;
        if(arr[mid] == target)
            return mid;
        if(arr[start] <= arr[mid]){
            if(arr[start] <= target && arr[end]>= target)
                return search(arr, target, start, mid-1);
            else
                return search(arr, target, mid+1, end);
        }

        if(target >= arr[mid] && target <= arr[end])
            return search(arr, target, mid+1, end);
        return search(arr, target, start, mid-1);
    }
}
