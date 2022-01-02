package RecursionQues1;

import java.util.Scanner;

public class Print1toNusingNto1 {
        // Print Numbers from 1 to N Using N to 1 Recursion
        public static void main(String [] args){
            // Creating Scanner Object for Taking Inputs from the USER
            Scanner sc = new Scanner(System.in);
            // take value of N from the USER
            System.out.print(" Enter Value of N: ");
            int n = sc.nextInt();
            funRev(n);
        }

        static void funRev(int n){
            if(n == 0)
                return;
            funRev(n -1);
            System.out.print(n + " ");
        }
    }
