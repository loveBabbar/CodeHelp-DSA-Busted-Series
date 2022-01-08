import java.util.Scanner;

class forLoop {
    public static void main(String[] args) {
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        n = sc.nextInt();
        sc.close();

        System.out.println("printing count from 1 to n");

        int i = 1;

        for (;;) {
            if (i <= n) {
                System.out.println(i);
            } else {
                break;
            }
            i++;
        }

        for (int a = 0, b = 1, c = 2; a >= 0 && b >= 1 && c >= 2; a--, b--, c--) {
            System.out.println(a + " " + b + " " + c);
        }
    }
}
