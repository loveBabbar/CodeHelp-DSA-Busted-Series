package RecursionQues1;

public class Concept {
    public static void main(String [] args){
        fun(5);
    }
    static void fun(int n){
        if(n == 0)
            return;
        System.out.print(n + " ");
        fun(--n);
//        fun(n--);  --> Will not Work Stack OverFlow
        // Recursion Tree for fun(n--)
        /*
        fun(5--) -> fun(5--) -> fun(5--) --> Stack Overflow
         */
        /*
                --n VS n--
        --n --> It will Subtract 1 from n First and then Pass
        n-- --> It will Pass the n First and then Subtract 1 from n

         */
    }

}
