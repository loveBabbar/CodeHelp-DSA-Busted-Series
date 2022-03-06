class BitwiseOperators {
    public static void main(String[] args) {

        int a = 4;
        int b = 6;

        System.out.println("a&b: " + (a & b));
        System.out.println("a|b: " + (a | b));
        System.out.println("~a: " + (~a));
        System.out.println("a^b: " + (a ^ b));

        System.out.println("17>>1: " + (17 >> 1));
        System.out.println("17>>2: " + (17 >> 2));
        System.out.println("19<<1: " + (19 << 1));
        System.out.println("19<<2: " + (19 << 2));

        int i = 7;

        System.out.println("++i: " + (++i)); // Ans 8
        System.out.println("i++: " + (i++)); // Ans 8, then 9

        System.out.println("--i: " + (--i)); // 8
        System.out.println("i--: " + (i--)); // 8, i=7

    }
}