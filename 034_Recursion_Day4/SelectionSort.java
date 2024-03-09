public class SelectionSort {
    public static void main(String[] args) {
        int[] arr = {6, 2, 8, 4, 10};
        int size = 5;

        sort(arr , 0 , size);

        for(int i = 0; i < size; i++){
            System.out.print(arr[i] + " ");
        }
    }

    public static void sort(int[] arr , int idx , int size)
    {
        //base case
        if(idx == size)
            return;

        int smallestIdx = idx; // take curr idx element as smallest

        for(int i = idx + 1; i < size; i++){
            if(arr[smallestIdx] > arr[i]) // found another smallest element than arr[smallestIdx]
                smallestIdx = i; // update the smallestIdx val
        }

        //place smallest element found at idx
        int temp = arr[idx];
        arr[idx] = arr[smallestIdx];
        arr[smallestIdx] = temp;

        // one part Done recursion will do other work;
        sort(arr , idx + 1 , size);
    }
}
