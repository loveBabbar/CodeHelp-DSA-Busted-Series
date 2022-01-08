import java.util.*;
class printCountingWithFunc {

    static void printCounting(int n) {
        for(int i=1; i<=n; i++) {
            System.out.print(i + " ");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        printCounting(n);
    }   
}
