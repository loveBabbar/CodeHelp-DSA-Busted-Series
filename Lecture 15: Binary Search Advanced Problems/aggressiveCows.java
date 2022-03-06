import java.util.*;

public class Solution 
{
    static boolean isPossible(ArrayList<Integer> stalls,int k,int mid){
        int cows = 1,n=stalls.size();
        int last = stalls.get(0);
        for(int i=0;i<n;i++){
            if(stalls.get(i)-last >= mid){
                cows++;
                if(cows==k)
                    return true;
                
                last = stalls.get(i) ;
            }
        }
        return false ;
    }
    public static int aggressiveCows(ArrayList<Integer> stalls, int k) 
    {
        int end = Collections.max(stalls);
        int start = 0,ans=-1;
        Collections.sort(stalls);
        
        int mid = start+(end-start)/2;
        while(start<=end){
            if(isPossible(stalls,k,mid)){
                ans = mid ;
                start = mid+1 ;
            }else{
                end = mid-1 ;
            }
            mid = start +(end-start)/2;
        }
        return ans;
    }
}