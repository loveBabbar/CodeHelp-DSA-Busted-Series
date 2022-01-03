public class Solution {
    static boolean isPossible(int time[],int n,int m,long mid){
        long days = 1 ;
        long chapter = 0;
        
        for(int i=0;i<m;i++){
            if(time[i]+chapter<=mid){
                chapter+=time[i];
            }else{
                days++;
                if(days>n || time[i]>mid)
                    return false ;
                chapter = time[i];
            }
        }
        return true ;
    }
    public static long ayushGivesNinjatest(int n, int m, int[] time) {
        long start = 0;
        long end =0,ans=-1 ;
        for(int i=0;i<m;i++)
            end+=time[i];
        
        long mid = start+(end-start)/2;
        while(start<=end){
            if(isPossible(time,n,m,mid)){
                ans = mid;
                end = mid-1 ;
            }else{
                start = mid+1 ;
            }
            mid = start+(end-start)/2 ;
        }
        return ans ;
    }
}