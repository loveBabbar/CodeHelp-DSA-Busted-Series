
public class Solution {

	public static int sqrtN(long N) {
		/*
		 * Write your code here
		 */
               long start = 0;

       long end = N;

       long ans=0;

       if(N==0)return 0;

       else if(N==1)return 1;

       while(start<=end)

       {

           long mid = start+(end-start)/2;

           if(mid==N/mid)return (int)mid;

           else if(mid>N/mid)end=mid-1;

           else  

           {

               ans=mid;

               start=mid+1;

           }

       }

       return (int)ans;


	}
}
