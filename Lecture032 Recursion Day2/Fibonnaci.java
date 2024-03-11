class Fibonnaci {
    public int fib(int n) {

        if(n <= 1)  //base case
            return n;

        return fib(n - 1) + fib(n - 2); // recurrence relation
    }
}
