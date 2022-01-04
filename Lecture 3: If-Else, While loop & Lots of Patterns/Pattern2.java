import java.util.Scanner;
public class Pattern2 {

 public static void main(String[] args) {
  
    Scanner cs=new Scanner(System.in);
     
      int row_size,out,in;
      row_size=cs.nextInt();
      for(out=1;out<=row_size;out++)
      {
       for(in=1;in<=row_size;in++)
        System.out.print(out);

            System.out.println();
      }
   }
}


/*
6
111111
222222
333333
444444
555555
666666
*/
