import java.util.*;

class PrimeNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n;

        // taking input
        n = sc.nextInt();

        sc.close();

        for (int i = 2; i < n; i++) {
            // if divisible, not prime
            if (n % i == 0) {
                System.out.println("Not prime for " + i);
            } else {
                System.out.println("Prime for " + i);
            }
        }
    }
}