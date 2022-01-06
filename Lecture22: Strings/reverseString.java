
class Solution {
    public void reverseString(char[] s) {
        int st=0;
        int e = s.length-1;

        while(st<e) {
            swap(s,st,e);
            st++;
            e--;
        }
    }
  
  public void swap(char[] arr,int i,int j){
    char temp;
    
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
