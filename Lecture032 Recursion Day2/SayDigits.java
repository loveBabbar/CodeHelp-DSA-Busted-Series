import java.util.Scanner;
public class SayDigits {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        String[] arr = {"Zero", "One", "Two", "Three", "Four",
                "Five", "Six", "Seven", "Eight",
                "Nine", "Ten"};

        sayNumber(n, arr);
    }

    public static void sayNumber(int n , String[] arr) {
        if (n == 0)  // base case
            return;

        int rem = n % 10;
        int nextDigit = n / 10;

        sayNumber(nextDigit, arr); // recursive relation

        System.out.print(arr[rem] + " "); // print the value while coming back from stack
    }
}
