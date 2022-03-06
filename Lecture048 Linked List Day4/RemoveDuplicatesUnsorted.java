import java.util.*;
public class Solution {
	
	public static LinkedListNode<Integer> removeDuplicates(LinkedListNode<Integer> head) {

        // Write your code here	
        
        if(head==null) return null;
        
        LinkedListNode<Integer> curr = head,prev = null;
        
        Set<Integer> set = new HashSet<>();
        
        while(curr!=null){
            if(set.contains(curr.data)){
                prev.next = curr.next;
                curr = prev.next;
            }
            
            else{
                set.add(curr.data);
                prev = curr;
                curr = curr.next;
            } 
        }
        
        return head;
	}

}