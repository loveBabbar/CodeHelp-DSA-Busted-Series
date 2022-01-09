package Recursion3;

import java.util.ArrayList;

public class Permutations2 {
    // Permutations
    public static void main(String [] args){
        String str = "Deep";
        System.out.println(permutation(str, ""));
    }

    static ArrayList<String> permutation(String str, String ans){
        if(str.isEmpty()){
//            System.out.println(ans);
            ArrayList<String> list = new ArrayList<>();
            list.add(ans);
            return list;
        }

        char ch = str.charAt(0);
        // Local to this Call
        ArrayList<String> ls = new ArrayList<>();

        for(int i=0; i <= ans.length(); i++){
            String first = ans.substring(0, i);
            String second = ans.substring(i, ans.length());
            ls.addAll(permutation(str.substring(1), first + ch + second));
        }
        return ls;
    }
}
