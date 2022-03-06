import java.util.*;
class nthFibonacciWithFunc {

    static int nthFibonacciTerm(int n) {
        int nthTerm = 1, previousToNTerm = 0, sum = 0;

        if(n <= 1) {
            return n;
        }

        for(int i=2; i<n; i++) {
            sum = nthTerm + previousToNTerm;
            previousToNTerm = nthTerm;
            nthTerm = sum;
        }

        return nthTerm;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        sc.close();

        System.out.println(n + "th Fibonacci Term is: " + nthFibonacciTerm(n));


    }    
}
