
class Solution {
  
   public static int find_pivot(ArrayList<Integer> v){

      int s = 0, e = v.size() - 1;
      int mid=(s + e) / 2;
      while (s < e)
      {
        if(v.get(mid) < v.get(mid+1))
         s=mid+1;
        else
          e = mid;

        mid = (s + e) / 2;
      }
      return s;
  }
    public static int peakIndexInMountainArray(ArrayList<Integer> arr) {
        return find_pivot(arr);
    }
}
