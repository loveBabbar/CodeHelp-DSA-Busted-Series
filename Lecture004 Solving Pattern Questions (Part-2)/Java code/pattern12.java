import java.util.Scanner;

public class pattern12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i=1;
        while(i<=n){
            int space =n-i;
            while(space>0){// if i don't put '>0' it show an error i found solution on youtube and then mentioned
                System.out.print(" ");
                space= space-1;
            }
            int j=1;
            while(j<=i){
                System.out.print("*");
                j++;
            }
            System.out.println();
            i++;
    }
    }
}
