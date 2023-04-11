
/************************************************************

    Following is the linked list node structure
    
    class Node<T> {
    T data;
    Node<T> next;

    public Node(T data) {
        this.data = data;
    }
}

************************************************************/
public class Solution {
  
  public static Node insertAtTail(Node tail, Node curr) {
        tail.next = curr;
        tail = curr; // setting tail pointer
        return tail;
  }
  
	public static Node<Integer> sortList(Node<Integer> head) {
        Node zeroHead = new Node(-1);
        Node zeroTail = zeroHead;
        Node oneHead = new Node(-1);
        Node oneTail = oneHead;
        Node twoHead = new Node(-1);
        Node twoTail = twoHead;

        Node curr = head;

        int zero = 0;
        int one = 0;
        int two = 0;

        // create separate list 0s, 1s and 2s
        while (curr != null) {

            int value = (int)curr.data;

            if (value == 0) {
                zero++;
                zeroTail = insertAtTail(zeroTail, curr);
            } else if (value == 1) {
                one++;
                oneTail = insertAtTail(oneTail, curr);
            } else if (value == 2) {
                two++;
                twoTail = insertAtTail(twoTail, curr);
            }
            curr = curr.next;
        }

        //merge 3 sublist

        // 1s list not empty
        if (oneHead.next != null) {
            zeroTail.next = oneHead.next;
        } else {
            //1s list -> empty
            zeroTail.next = twoHead.next;
        }

        oneTail.next = twoHead.next;
        twoTail.next = null;

        //setup head 
        head = zeroHead.next;

        //delete dummy nodes
        zeroHead = null;
        oneHead = null;
        twoHead = null;

        return head;
  }

}
