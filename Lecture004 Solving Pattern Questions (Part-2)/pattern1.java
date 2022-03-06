import java.util.*;

public class pattern1 {
    public static void main(String[] args) {
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");

        n = sc.nextInt();
        sc.close();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                System.out.print((n - j + 1) + " ");
            }
            System.out.println();
        }
    }
}
