package MathsForDSA;

public class GCD {
    // Find GCD of Two Numbers
    public static void main(String [] args){
        int a = 4;
        int b = 9;
        System.out.format(" Gcd of %d and %d is: %d ", a, b, gcd(a,b));
    }
    static int gcd(int a, int b){
        if(a == 0)
            return b;
        return gcd(b % a , a);
    }
}
