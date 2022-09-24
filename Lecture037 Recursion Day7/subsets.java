package com.company;
import java.util.*;

public class subsets {
    public static void solve(int[] nums,List<Integer> output,int index,List<List<Integer>> ans ){
        ans.add(new ArrayList<>(output));
        for(int i = index; i < nums.length; i++){
            output.add(nums[i]);
            solve(nums, output, i + 1,ans);
            output.remove(output.size() - 1);
        }


    }
    public static List<List<Integer>> subsets(int[] nums) {
        List<Integer> output = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList();

        solve(nums,output,0,ans);
        return ans;
    }
    public static void main(String[] args) {
        int [] arr = {1,2,3};
        System.out.println(subsets(arr));
    }
}
