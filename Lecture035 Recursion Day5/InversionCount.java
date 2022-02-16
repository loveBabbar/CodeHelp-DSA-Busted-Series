class InversionCount
{
    // arr[]: Input Array
    // N : Size of the Array arr[]
    //Function to count inversions in the array.
    static long inversionCount(long[] arr, long N)
    {
        return count(arr , 0 , N - 1);
    }

    public static long count(long[] arr , long s , long e){
        //base case
        if(s >= e)
            return 0;

        long mid = (s + e) / 2;

        //left Part inversion
        long inv = count(arr , s , mid);
        inv += count(arr , mid + 1 , e);
        inv += merge(arr , s , e);
        return inv;
    }

    public static long merge(long[] arr , long s , long e){
        long ans = 0;

        int mid = (int)(s + e)/2;

        int l1 = mid - (int)s + 1;
        int l2 = (int)e - mid;

        long[] a1 = new long[l1];
        long[] a2 = new long[l2];

        int idx = (int)s;

        //copy elements
        for(int i = 0; i < l1; i++){
            a1[i] = arr[idx++];
        }

        for(int i = 0; i < l2; i++){
            a2[i] = arr[idx++];
        }

        int idx1 = 0;
        int idx2 = 0;
        idx = (int) s;
        while(idx1 < l1 && idx2 < l2){
            //check for inversions

            if(a1[idx1] > a2[idx2]){
                ans += (l1 - idx1);

                arr[idx++] = a2[idx2++];
            }
            else {
                arr[idx++] = a1[idx1++];
            }
        }

        while(idx1 < l1){
            arr[idx++] = a1[idx1++];
        }
        while(idx2 < l2){
            arr[idx++] = a2[idx2++];
        }

        return ans;
    }
}
