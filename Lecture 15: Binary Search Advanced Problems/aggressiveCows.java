public static boolean isPossible(ArrayList<Integer> stalls, int k, int mid, int n) {
    
    int cowCount = 1;
    int lastPos = stalls.get(0);
    
    for(int i=0; i<n; i++ ){
        
        if(stalls.get(i)-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos = stalls.get(i);
        }
    }
    return false;
}

public static int aggressiveCows(ArrayList<Integer> stalls, int k)
{
    Collections.sort(stalls);
   	int s = 0;
    int n = stalls.size();
    int e=stalls.get(n-1);
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e) {
        if(isPossible(stalls, k, mid, n)) {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
