class LinearSearchJava {
  public static void main(String[] args) {
    int arr[] = new int[] { 1, 2, 3, 4 };
    int key = 10;
    System.out.println(linearSearch(arr, arr.length-1, key));
  }

  public static boolean linearSearch(int arr[], int n, int key) {
    if(n == 0) return arr[n] == key;
    if(arr[n] == key) return true;
    else {
      boolean ans = linearSearch(arr, n-1, key);
      return ans;
    }
  }
}