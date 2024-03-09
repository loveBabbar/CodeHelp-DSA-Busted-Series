public class NumberOfDigitsInBaseb {
    // find Number of Digits in Base b
    public static void main(String [] args){
        int n = 8;
        int num = n;
        int count = 0;
        while(n > 0){
            n = n >> 1;
            count ++;
        }
        System.out.println(" Number of Digits of " + num + " in Binary Format are: " + count);
    }
}
