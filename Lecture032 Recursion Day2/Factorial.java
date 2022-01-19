import java.util.Scanner;

public class Factorial {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Scanner to read values from user

        int n = sc.nextInt(); // take input from user

        int ans = fact(n); // calling fact function to compute our factorial value of n

        System.out.println(ans); // print the ans
    }

    public static int fact(int n){ // function to find the factorial
        //Base case
        if(n == 0)
            return 1;

        // Recurrence relation
        int smallerProblem = fact(n - 1);
        int biggerProblem = n * smallerProblem;

        //  can be also written as
        //  biggerProblem = n * fact(n - 1);

        return biggerProblem;
    }
}
