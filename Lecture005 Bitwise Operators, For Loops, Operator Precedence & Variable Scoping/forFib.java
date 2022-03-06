class forFib {
    public static void main(String[] args) {
        int n = 10;

        int a = 0;
        int b = 1;

        System.out.print(a + " " + b + " ");

        for (int i = 1; i <= n; i++) {
            int nextNumber = a + b;
            System.out.print(nextNumber + " ");

            a = b;
            b = nextNumber;
        }
    }
}
