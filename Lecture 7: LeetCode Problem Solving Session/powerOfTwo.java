class Solution {
    public boolean isPowerOfTwo(int n) {
        for (int i = 0; i <= 30; i++) {
            boolean validator = (Math.pow(2, i) == n);
            if (validator)
                return true;
        }

        // Alternative Approach
        // if(n<=0) return false;
        // return (n & (n-1)) == 0;

        return false;
    }
}