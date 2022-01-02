package RecursionQues1;

public class CountNumberOfZeros {

    public static int countZeros(int n){
        return helper(n, 0);
    }

    static int helper(int n, int c){
        if(n == 0)
            return c;
        int rem = n%10;
        if(rem == 0)
            return helper(n/10, c+1);
        else
            return helper(n/10, c);
    }

    public static void main(String [] args){
        int n = 3002;
        System.out.println(countZeros(n));
    }
}
