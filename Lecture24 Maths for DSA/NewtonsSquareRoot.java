package MathsForDSA;

public class NewtonsSquareRoot {
    // Calculating Square Root of a Number Using Newton's Square Root Method
    public static void main(String [] args){
        double num = 40;
        // Display the Square Root of n
        System.out.println(" Square Root of " + num + " is: " + sqrt(num));
    }

    static double sqrt(double n){
        double x = n;
        double root;
        while(true){
            root = 0.5 * (x + (n/x));   // Similar to Root = ( X + N/X ) / 2
            if(Math.abs(root - x) < 0.5)
                break;
            x = root;
        }
        return root;
    }
}
