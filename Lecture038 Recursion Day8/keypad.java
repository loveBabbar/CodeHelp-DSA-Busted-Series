//Leetcode Solution for Letter Combinations of a phone number
public class Solution {    
    	public List<String> letterCombinations(String digits) {
    		List<String> result = new LinkedList<String>();
            if(digits == null || digits.length() == 0) return result;
            String[] keys = { "", "", "abc", "def", "ghi", "jkl",
                             "mno", "pqrs", "tuv", "wxyz" };
    		combination("", digits, 0, result , keys);
    		return result;
    	}
    
    	private void combination(String prefix, String digits, int index, List<String> result ,String[] keys) {
    		if (index >= digits.length()) {
    			result.add(prefix);
    			return;
    		}
    		String letters = keys[(digits.charAt(index) - '0')];
    		for (int i = 0; i < letters.length(); i++) {
                prefix = prefix + letters.charAt(i);
    			combination(prefix , digits, index + 1, result, keys);
                prefix = prefix.substring(0,prefix.length() - 1);
    		}
    	}
    }