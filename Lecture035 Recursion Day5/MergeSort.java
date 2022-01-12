
public class MergeSort {

    public static void merge(int arr[], int l, int m, int r)
    {
        
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[] = new int[n1];
        int R[] = new int[n2];

        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];


        int i = 0, j = 0;

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    public static void mergeSort(int[] arr, int s, int e){
        if (s < e) {
            // Find the middle point
            int m =s+ (e-s)/2;

            // Sort first and second halves
            mergeSort(arr, s, m);
            mergeSort(arr, m + 1, e);

            // Merge the sorted halves
            merge(arr, s, m, e);
        }
    }

    public static void main(String[] args) {
        
        int arr[] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
        int n = 15;

        mergeSort(arr, 0, n-1);

        for(int i=0;i<n;i++){
            System.out.print(arr[i] + " ");
        } 
        System.out.println();
    }
}
