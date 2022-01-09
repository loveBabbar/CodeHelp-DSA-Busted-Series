package com.company;

public class PerformanceOfStrings {
    // Performance of Strings --> IMPORTANT
    public static void main(String [] args){
        String series = "";
        for(int i=0; i < 26; i++){
            char ch = (char)('a' + i);
            System.out.println(ch);
        }

        String series1 = "";
        for(int i=0; i < 26; i++){
            char ch = (char)('a' + i);
            series1 += ch;
        }
        System.out.println(series1);

        // String Builder --> it is also a Class like String
    }
}
