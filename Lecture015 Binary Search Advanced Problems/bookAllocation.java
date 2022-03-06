import java.util.ArrayList;

public class Solution {
    
    static boolean isPossible(ArrayList<Integer> arr, int n, int m, int mid) {
    	int studentCount = 1;
    	int pageSum = 0;
    //sout << "checking for mid "<< mid <<endl;
    
    	for(int i = 0; i<n; i++) {
        	if(pageSum + arr.get(i) <= mid) {
            	pageSum += arr.get(i);
        	}
        	else
        	{
            	studentCount++;
            	if(studentCount > m || arr.get(i) > mid ) {
            	return false;
       		}
            pageSum = arr.get(i);
        }
        if(studentCount > m) {
            return false;
        }
        //sout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

    
public static int allocateBooks(ArrayList<Integer> arr, int n, int m) {
        // Write your code here.
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr.get(i);
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
    }
}


