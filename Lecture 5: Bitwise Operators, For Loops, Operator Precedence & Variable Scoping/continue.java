class ContinueKeyword {
    public static void main(String[] args) {

        for (int i = 0; i < 5; i++) {

            System.out.println("HI");
            System.out.println("HEY");
            continue;

            // Java being a predictable language
            // shows error
            // that this line will be unreachable
            // System.out.println("Reply toh karde");

        }

    }
}
