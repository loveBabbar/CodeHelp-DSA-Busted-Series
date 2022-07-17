import java.util.*;
class pattern13 {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int n = sc.nextInt();
        int i=1;
        while(i<=n){
            int space = n-i;
            while(space>0){
                System.out.print(" ");
                space = space -1;
        }
        // print 2nd tringle
        int j=1;
        while(j<=i){
            System.out.print(j);
            j++;
        }
        // print 3rd tringle
        int start=i-1;
        while(start>0){
            System.out.print(start);
            start=start-1;
        }
        System.out.println();
        i++;

        }
    }
}
