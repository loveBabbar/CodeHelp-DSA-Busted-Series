class SumJava {
  public static void main(String[] args) {
    int arr[] = new int[] { 1, 2, 3, 4 };

    System.out.println(sumArr(arr, arr.length-1));
  }

  public static int sumArr(int arr[], int n) {
    if(n == 0) return arr[n];
    int remainingSum = sumArr(arr, n-1);
    int ans = arr[n] + remainingSum;
    return ans;
  }
}