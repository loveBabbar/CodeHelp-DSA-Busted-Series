//program to implement merge sort algorithm
//first of all we break the array into smallest possible unit possible i.e a single element
//a single element is already sorted
//so now we just keep merging the sorted array until we get the sorted array
//for merging used the linear time complexity technique of merging two sorted array

class MergeSort {
    void conquer(int arr[], int start, int mid, int end)
    {
        int merge[] = new int[end - start + 1];
        int index1 = start;   //index for the first part
        int index2 = mid + 1; //index for the second part
        int mergeIndex = 0;   //index for the merged array

        while (index1 <= mid && index2 <= end)
        {
            if (arr[index1] <= arr[index2])
                merge[mergeIndex++] = arr[index1++];
            else
                merge[mergeIndex++] = arr[index2++];
        }

        //in case the two parts are not of equal length we need to add the remaining elements to the array
        while (index1 <= mid)
        {
            merge[mergeIndex++] = arr[index1++];
        }

        while (index2 <= end)
        {
            merge[mergeIndex++] = arr[index2++];
        }

        for (int i = 0, j = start; i < end - start + 1; j++, i++)
        {
            arr[j] = merge[i];
        }
    }

    void divide(int arr[], int start, int end)
    {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;
        //we could have used (start + end)/2 but it may lead to data type limit exceeding for large array
        divide(arr, start, mid);
        divide(arr, mid + 1, end);
        conquer(arr, start, mid, end);
    }

    void printArray(int A[], int size)
    {
        int i;
        for (i = 0; i < size; i++)
            System.out.print(A[i]+" ");
        System.out.println();
    }

    public static void main(String[] args) {

        MergeSort ob = new MergeSort();
        int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int arrayLength = a.length;

        System.out.println("Array before sorting");
        ob.printArray(a, arrayLength);

        ob.divide(a, 0, arrayLength-1);

        System.out.println("Array after sorting");
        ob.printArray(a, arrayLength);

    }

}