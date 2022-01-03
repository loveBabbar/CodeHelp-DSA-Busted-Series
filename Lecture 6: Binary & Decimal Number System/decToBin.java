import java.util.*;

class decToBin {
    public static void main(String[] args) {
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        n = sc.nextInt();
        sc.close();

        int ans = 0;

        for (int i = 0; n != 0; i++) {
            int bit = n & 1;

            ans = (int) (bit * (Math.pow(10, i)) + ans);

            n = n >> 1;
        }

        System.out.println("Answer is: " + ans);
    }
}
