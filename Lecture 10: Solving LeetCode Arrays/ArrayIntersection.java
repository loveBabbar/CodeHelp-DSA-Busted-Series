import java.util.*;

public class Solution
{
	public static ArrayList<Integer> findArrayIntersection(ArrayList<Integer> arr1, int n, ArrayList<Integer> arr2, int m)
	{
		// Write Your Code Here.
        
        ArrayList<Integer> ans = new ArrayList<>();
        
//         initalising pointers for both ArrayLists
        int ptr1 = 0,ptr2 = 0;
        
        while(ptr1<n && ptr2<m){
            
//             storing elements of both ArrayList at current iteration
            int arr1_item = arr1.get(ptr1);
            int arr2_item = arr2.get(ptr2);
            
//             if both elements equal add it to ans and increment both pointers
            if(arr1_item==arr2_item){
                ans.add(arr1_item);
                ptr1++;
                ptr2++;
            }
            
            else if(arr1_item<arr2_item) ptr1++;
            
            else ptr2++;
        }
        
        return ans;
	}
}
