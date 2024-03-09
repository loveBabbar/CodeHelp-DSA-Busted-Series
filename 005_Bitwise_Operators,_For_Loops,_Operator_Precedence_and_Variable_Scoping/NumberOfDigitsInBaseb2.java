public class NumberOfDigitsInBaseb2 {
    // Number of Digits in Base b using log
    public static void main(String [] args){
        int n = 12;
        int base = 2;
        int numberOfDigits = (int)(Math.log(n) / Math.log(base)) + 1;
        System.out.println(" Number of Digits in " + n + " with base " + base + " is: " + numberOfDigits);
    }
}
