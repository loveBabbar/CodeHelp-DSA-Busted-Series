class SortedArrayJava {
  public static void main(String[] args) {
    int arr[] = new int[] { 0, 2, 3, 4, 5, 7, 8 };

    System.out.println(isSorted(arr, arr.length-1));
  }

  public static boolean isSorted(int arr[], int n) {
    if(n == 0) return true;
    if(arr[n] < arr[n-1]) return false;
    else {
      boolean ans = isSorted(arr, n-1);
      return ans;
    }
  }
}