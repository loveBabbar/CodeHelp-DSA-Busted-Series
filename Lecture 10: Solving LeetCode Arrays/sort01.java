static void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        System.out.print(arr[i]);
    }
    System.out.println();
}

static void sortOne(int arr[], int n) {

    int left = 0, right = n-1;

    while(left < right) {

        while(arr[left] == 0 && left < right )  {
            left++;
        }

        while(arr[right]==1 && left < right){
            right--;
        }

        //agar yha pohoch gye ho, iska matlab
        //arr[left]==1 and arr[right]==0
        if(left<right)
        {
            swap(arr,left,right);
            left++;
            right--;
        }
    }

}

public static void swap(int[] arr,int i,int j){
  int temp;
  
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

public static void main(String[] args) {

    int arr[] = {1,1,0,0,0,0,1,0};

    sortOne(arr, 8);
    printArray(arr, 8);
}
