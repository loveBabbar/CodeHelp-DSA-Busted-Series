// Three-Pointers Approach

public class Solution  
{
    public static void sort012(int[] arr)
   {
       int start = 0;
       int mid = 0;
       int end = arr.length-1;

       while(end>=mid)
       {
           if(arr[mid]==0)
           {
               int temp= arr[mid];
               arr[mid]=arr[start];
               arr[start]=temp;  
               start++;
               mid++;
           }
           else if(arr[mid]==2)
           {  
               int temp= arr[mid];
               arr[mid]=arr[end];
               arr[end]=temp;
               end--;
           }
           else //(arr[mid]==1)
           {
             mid++;
           }
       }
   }
}
