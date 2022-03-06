
/************************************************************

    Following is the linked list node structure
    
    class LinkedListNode<T> {
    T data;
    LinkedListNode<T> next;

    public LinkedListNode(T data) {
        this.data = data;
    }
}

************************************************************/

public class Solution {
	
	public static void splitCircularList(LinkedListNode<Integer> head) {
        
        LinkedListNode<Integer> slow = head,fast = head.next.next;
        
        // finding the middle of LL
        while(fast!=head){
            slow = slow.next;
            
            fast = fast.next.next;
            
        }
        
        LinkedListNode<Integer> temp = slow.next;
        
        // splitting 1st half of LL
        slow.next = head;
        
        LinkedListNode<Integer> curr = temp;
        
        while(curr.next!=head) curr = curr.next;
        
        // splitting 2nd half of LL
        curr.next = temp;
	}

}