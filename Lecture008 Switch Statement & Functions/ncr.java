import java.util.*;
class ncr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int r = sc.nextInt();

        System.out.println("Answer: " + combination(n, r));
    }
    
    // nCr Formula: factorial(n) / factorial(r) * factorial(n-r)

    static int combination(int n, int r) {
        int num = factorial(n);
        int denom = factorial(r) * factorial(n-r);

        return num/denom;
    }

    static int factorial(int n) {
        int fact = 1;

        for(int i=1; i<=n; i++){
            fact *= i;
        }

        return fact;
    }
}
