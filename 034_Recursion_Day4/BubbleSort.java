public class BubbleSort {
    public static void main(String[] args) {
        //Array to be sorted
        int[] arr = {2 , 8 , 4 , 9 , 5};
        //size of array
        int n = 5;

            //printing array before sorting
        System.out.println("Before");

        for(int i : arr){
            System.out.print(i + " ");
        }

        System.out.println();

        //recursive call
        sortRecursive(arr , n);

            //print array after sorting
        System.out.println("After");

        for(int i : arr){
            System.out.print(i + " ");
        }
    }
    public static void sortRecursive(int[] arr , int n){
        //base case
        if(n == 0 || n == 1)
            return;

        for(int i = 0; i < n - 1; i++){
            if(arr[i] > arr[i + 1]){
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
         sortRecursive(arr , n - 1);
    }
}
