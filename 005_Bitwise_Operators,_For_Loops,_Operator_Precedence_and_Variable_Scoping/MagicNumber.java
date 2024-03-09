public class MagicNumber {
    // Find the nth Magic Number
    public static void main(String [] args){
        int n = 9;
        int ans = 0;
        int base = 5;
        while(n > 0){
            // Find Last Digit of Binary number by and with 1
            int lastDigit = n & 1;
            ans = lastDigit * base;
            base  = base * 5;
            n = n >> 1;
        }

        System.out.println(" Ans is: " + ans);
    }
}
