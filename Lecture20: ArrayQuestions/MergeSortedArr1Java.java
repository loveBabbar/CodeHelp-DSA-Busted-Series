class MergeSortedArr1Java {
  public static void main(String[] args) {
    int arr1[] = new int[] {1,3,5,7,9,0,0,0};
    int arr2[] = new int[] {2,4,6};
    int m = 5;
    int n = 3;
    mergeSortedArrLeetcode(arr1, m, arr2, n);

    int arr3[] = new int[] {1,3,5,7,9};
    int arr4[] = new int[8];
    mergeSortedArr(arr3, 5, arr2, 3, arr4);
  }

  public static void mergeSortedArrLeetcode(int arr1[], int m, int arr2[], int n) {
    int i = m-1;
    int j = n-1;
    int k = arr1.length-1;

    while(i >=0 && j >= 0) {
      if(arr1[i] > arr2[j]) {
        arr1[k--] = arr1[i--];
      } else {
        arr1[k--] = arr2[j--];
      }
    }
        
    while(j >= 0) {
      arr1[k--] = arr2[j--];
    }

    //printing array
    for(int ele : arr1) {
      System.out.print(ele+" ");
    }
  }

  public static void mergeSortedArr(int arr1[], int n, int arr2[], int m, int arr3[]) {
    int i = 0, j = 0;
    int k = 0;
    while( i<n && j<m) {
        if(arr1[i] < arr2[j]){
          arr3[k++] = arr1[i++];
        }
        else{
          arr3[k++] = arr2[j++];
        }
    }

    //copy first array k element ko
    while(i<n) {
      arr3[k++] = arr1[i++];
    }

    //copy kardo second array k remaining element ko
    while(j<m) {
      arr3[k++] = arr2[j++];
    }

    System.out.println();
    System.out.println("from mergeSortedArr method");
    //printing array
    for(int ele : arr3) {
      System.out.print(ele+" ");
    }
  }
}