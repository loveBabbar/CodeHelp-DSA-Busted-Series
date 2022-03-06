class Solution {
    public void reverseString(char[] s) {
        //using two pointers method
        int leftPointer =0;
        int rightPointer=s.length-1;
        
        while(leftPointer<rightPointer){
            char temp = s[leftPointer];
            s[leftPointer++]=s[rightPointer];
            s[rightPointer--]=temp;
        }
    }
}
       
