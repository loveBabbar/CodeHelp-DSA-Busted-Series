package BitManipulation;

public class FindithBitOfNumber {
    // Find ith Bit of the given Binary Number
    public static void main(String [] args){
        int a = 1100101;
        // Find 2nd Bit of the Number
        int n = 2;
        System.out.println(n + " Bit of " + a + " is: " + Integer.toBinaryString(n & (1 << n -1)));
    }
}
