import java.util.*;

class Pattern1 {
    public static void main(String[] args) {

        int n;
        System.out.print("Enter a number: ");
        Scanner sc = new Scanner(System.in);

        // taking input from user
        n = sc.nextInt();

        // closing sc to avoid unnecessary memory usage
        sc.close();

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n; j++) {
                System.out.print("*");
            }

            System.out.println();
        }
    }
}