public static void sortArray(int[] arr, int n) {

    //base case - already sorted
    if(n == 0 || n == 1) {
      for(int i=0; i<5; i++) {
        System.out.print(arr[i]+" ");
      }
        return ;
    }

    //1 case sovle karlia - largest element ko end me rakh dega
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1]){
            swap(arr,i,i+1);
        }
    }

    //Recursive Call
    sortArray(arr, n-1);

}

public static void swap(int[] arr,int i,int j){
  int temp;
  
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

public static void main(String[] args) {

    int arr[] = {2,5,1,6,9};
    
    sortArray(arr,5);

}
