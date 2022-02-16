public class PowerOf2OrNot {
    // Find Whether a Number is Power of 2 or Not
    public static void main(String [] args){
        int num = 12;
        int n = num;
        int count = 0;
        while(num > 1){
            num = num >> 1;
            if(num == 1)
                count++;
        }
        if(count == 1)
            System.out.println(" YES " + n + " is Power of Two");
        else
            System.out.println(" NO " + n + " is not Power of Two");
    }
}
