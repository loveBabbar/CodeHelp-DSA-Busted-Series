import java.util.Scanner;

public class patttern6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i=1;
        while(i<=n){
            int j=1;
            int value =i;
            while(j<=i){
                System.out.print(value+ " ");
                value++;
                j++;
            }
            System.out.println();
            i++;
        }
    }
}
