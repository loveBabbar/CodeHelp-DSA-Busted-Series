package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class CountItemsMatchingARule {
    // Count Items Matching a Rule
    public static void main(String [] args){
        /*
        Count Items Matching a Rule
        https://leetcode.com/problems/count-items-matching-a-rule/
        You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item.
         You are also given a rule represented by two strings, ruleKey and ruleValue.
        The ith item is said to match the rule if one of the following is true:
            ruleKey == "type" and ruleValue == typei.
            ruleKey == "color" and ruleValue == colori.
            ruleKey == "name" and ruleValue == namei.
            Return the number of items that match the given rule.
Example 1:
        Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]],
         ruleKey = "color", ruleValue = "silver"
        Output: 1
        Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
         */
        // Creating Scanner Object for taking Input From the User
        Scanner sc = new Scanner(System.in);

       // Creating 2D Array List
        List<List <String>> items = new ArrayList<>();
        for(int i=0;i<3;i++){
            items.add(new ArrayList<>());
        }

       for(int i=0;i<items.size();i++){
           for(int j=0;j<items.size();j++){
               items.get(i).add(sc.next());
           }
       }
       // Display the Array List
        System.out.println(items);

        int count = countMatches(items, "type", "phone");

        // Displaying Count
        System.out.println(" Count " + count);

    }
    public static int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int index = -1;   // initially let index Value as -1 for Wrong Inputs
        /*
        Now Update the index According to different Values of ruleKey
          index -->     0      1      2
          items[i] = [typei, colori, namei]
         */
        switch (ruleKey) {
            case "type" -> index = 0;
            case "color" -> index = 1;
            case "name" -> index = 2;
        }

        /*
        Now take Count initially 0
         */
        int count = 0;
        // for Every row in Array items check Following
        for(List<String> row: items){
            // Check is in row at a Particular Index of RULE-KEY  is the ruleValue Exist or Not?
            // If Yes then Increment the Count
            // Otherwise check for Next ROW of 2D ARRAY-List items
                if(row.get(index).equals(ruleValue)){
                    count++;
                }
        }
        // At the End Return the Count
        return  count;
    }
}
