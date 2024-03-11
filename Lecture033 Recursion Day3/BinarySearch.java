public class BinarySearch {
    public static void main(String[] args) {
        int[] arr = {2 ,3 , 4 ,10 , 12, 122};
        int key = 3;

        int ans = findIdx(arr , 0 , 5  , key);

        if(ans == -1)
            System.out.println("Not Found");

        else
            System.out.println("Element present at index " + ans);
    }
    public static int findIdx(int[] arr , int s , int e , int key){
        //base case
        if(s > e)
            return -1;
        //find mid
        int mid = s + (e - s)/2;

        if(arr[mid] == key) // key is found
            return mid;

        if(arr[mid] < key) // search in right part
            return findIdx(arr , mid + 1 , e , key); // recurrence relation
        else // search in left part
            return findIdx(arr , s , mid - 1 , key);// recurrence relation
    }
}
