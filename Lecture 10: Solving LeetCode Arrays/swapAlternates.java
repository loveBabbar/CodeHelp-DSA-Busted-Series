static void printArray(int arr[], int n) {

    for(int i = 0; i<n; i++ ) {
        System.out.print(arr[i]+" ");
    }
  
    System.out.println();
}

static void swapAlternate(int arr[], int size) {

    for(int i = 0; i<size; i+=2 ) {
        if(i+1 < size) {
            swap(arr,i,i+1);
        }
    }

}

static void swap(int[] arr,int i,int j){
    int temp;
    
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

public static void main(String[] args) {

    int even [] = {5,2,9,4,7,6,1,0};
    int odd [] = {11, 33, 9, 76, 43};

    swapAlternate(even, 8);
    printArray(even, 8);

    System.out.println();

    swapAlternate(odd, 5);
    printArray(odd, 5);

}
