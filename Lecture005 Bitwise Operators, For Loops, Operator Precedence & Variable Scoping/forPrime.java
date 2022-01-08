import java.util.Scanner;

class forPrime {
    public static void main(String[] args) {
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        n = sc.nextInt();
        sc.close();

        boolean isPrime = true;

        for (int i = 2; i < n; i++) {
            // rem is 0, not a prime
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            System.out.println("is a prime number.");
        } else {
            System.out.println("not a prime number.");
        }
    }
}
