package Recursion3;

public class PermutationCount {
    // Permutations Count
    public static void main(String[] args) {
        String str = "Deep";
        System.out.println(permutation(str, ""));
    }

    static int permutation(String str, String ans) {
        if (str.isEmpty()) {
            return 1;
        }

        char ch = str.charAt(0);
        int count = 0;

        for (int i = 0; i <= ans.length(); i++) {
            String first = ans.substring(0, i);
            String second = ans.substring(i, ans.length());

            count = count + permutation(str.substring(1), first + ch + second);
        }
        return count;
    }
}

