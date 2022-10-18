import java.util.*;

class Solution {
	static void reverse(char[] s,int i,int j){
		if(i>j){
			return;
		}
		swap(s,i,j);
		i++;
		j--;
		reverse(s,i,j);
	}
  
	static void swap(char[] s,int i,int j){
		char t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
	
	public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    
		char[] temp = s.toCharArray(); //convert the string to char array
		reverse(temp,0,temp.length-1);  
    
		System.out.println(String.valueOf(temp));
    sc.close();
	}
  
  
}
