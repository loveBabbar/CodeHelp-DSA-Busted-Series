package com.company;
import  java.util.*;
public class Subsequences {
    static void solve(String str,int index, ArrayList<String> ans,String output){
        if(index>=str.length()){
            ans.add(output);
            return;
        }
        solve(str,index+1,ans,output);
        output = output+str.charAt(index);
        solve(str,index+1,ans,output);

    }
    public static ArrayList<String> subsequences(String str) {
        // Write your code here
        ArrayList<String> ans =new ArrayList<>();
        String output ="";
        solve(str,0,ans,output);
        ans.remove(0);
        Collections.sort(ans);
        return ans;
    }
    public static void main(String[] args) {
        String str ="abc";

        System.out.println(subsequences(str));
    }
}
