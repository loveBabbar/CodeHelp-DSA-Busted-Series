package Recursion3;

public class Permutations {
    // Permutations
    public static void main(String [] args){
        String str = "Deepak";
        permutation(str, "");
    }

    static void permutation(String str, String ans){
        if(str.isEmpty()){
            System.out.println(ans);
            return;
        }

        char ch = str.charAt(0);

        for(int i=0; i <= ans.length(); i++){
            String first = ans.substring(0, i);
            String second = ans.substring(i, ans.length());

            permutation(str.substring(1), first + ch + second);
        }
    }
}
