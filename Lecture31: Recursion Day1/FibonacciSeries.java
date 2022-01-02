package RecursionQues1;

public class FibonacciSeries {
    public static void main(String [] args){
        System.out.println(fib(7));
//        System.out.println(fib(50));  // Why Not Giving the Ans --> Because of repetitions of same Values and Exponential Time Complexity
    }

    static int fib(int n){
        // Base Condition
        if(n < 2)
            return n;
        /*
         Base Conditions
         if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        */
        return fib(n - 1 ) + fib( n - 2 );
    }
}
