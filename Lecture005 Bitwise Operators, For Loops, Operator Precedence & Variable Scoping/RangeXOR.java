public class RangeXOR {
    // Range XOR
    public static void main(String [] args){
        // Range XOR from a, b --> xor(b) ^ xor(a - 1)
        int a = 3;
        int b = 9;
        int ans = xor(b) ^ xor(a - 1);
        System.out.println(ans);

        // This is Only for check this will give TLE for Large Numbers
        int ans2 = 0;
        for(int i= a; i<= b; i++)
            ans2 ^= i;
        System.out.println(ans2);

    }

    // This Function will XOR from 0 to a
    static int xor(int a){
        if(a % 4 == 0)
            return a;
        else if(a % 4 == 1)
            return 1;
        else if(a % 4 == 2)
            return a+1;
        return 0;
    }
}
