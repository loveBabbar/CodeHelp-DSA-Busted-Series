import java.util.Scanner;

public class Factorial {

    static long factorial(long n){
        if (n == 0) {
            return 1;
        }

        long smaller = factorial(n-1);
        long larger = n * smaller;

        return larger;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long ans = factorial(n);
        System.out.println(ans);
    }
}
