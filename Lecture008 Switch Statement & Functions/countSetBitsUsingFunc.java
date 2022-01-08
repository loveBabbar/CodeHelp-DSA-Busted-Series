import java.util.*;
class countSetBitsUsingFunc {

    static int countSetBits(int num) {
        int sum=0;
        while(num!=0){
            if((num&1) == 1) {
                sum++;
            }
            num = num>>1;
        }

        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();

        sc.close();

        int count = 0;

        count += countSetBits(a);
        count += countSetBits(b);

        System.out.println("Total no. of set bits in " + a + " and " + b + " is: " + count);
    }    
}
