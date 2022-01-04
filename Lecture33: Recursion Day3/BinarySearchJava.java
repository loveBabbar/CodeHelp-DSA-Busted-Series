class BinarySearchJava {
  public static void main(String[] args) {
    int arr[] = new int[] { 1, 2, 3, 4 };
    int key = 1;
    System.out.println(binarySearch(arr, 0, arr.length-1, key));
  }

  public static boolean binarySearch(int arr[], int start, int end, int key) {
    if(start > end) return false;
    
    int mid = start+(end-start)/2;

    if(arr[mid] == key) return true;    
    
    if(arr[mid] < key)
      return binarySearch(arr, mid+1, end, key);
    else return binarySearch(arr, start, mid-1, key);
  }
}