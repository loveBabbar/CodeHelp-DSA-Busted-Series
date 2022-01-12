public class Exponent {

    public static int power(int a, int b) {
        if(b == 0 ){
            return 1;
        }

        if( b == 1){
            return a;
        }

        int ans = power(a, b/2);

        
        if(b%2 == 0) {
            return ans * ans;
        }
        else {
            
            return a * ans * ans;
        }
    }

    public static void main(String[] args) {
        System.out.println(power(5, 2));
    }
}
