import java.util.*;

class Pattern2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.print("Enter a number: ");

        // taking input
        n = sc.nextInt();

        // closing scanner to avoid memory usage
        sc.close();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }

    }

}