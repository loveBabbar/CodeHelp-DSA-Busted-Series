class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {

        int count = 0;

        for (int i = 1; i <= 32; i++) {
            if ((n & 1) == 1) {
                count++;
            }
            n = n >> 1; // right shift all the bits by one place
        }

        return count;

    }
}
