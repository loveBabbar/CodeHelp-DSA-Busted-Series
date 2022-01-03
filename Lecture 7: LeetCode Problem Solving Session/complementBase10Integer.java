class Solution {
    public int bitwiseComplement(int n) {

        int m = n;
        int mask = 0;

        if (m == 0) {
            return 1;
        }

        while (m != 0) {
            mask = (mask << 1) | 1; // adds 1 to mask bits
            m = m >> 1; // to get the exact number of digits in `n` and run the loop till then
        }

        int ans = (mask & (~n)); // formula
        return ans;

    }
}