import java.util.ArrayList;

public class SplitSLL {
    static class Node
    {
        int data;
        Node next;
        Node(int data)
        {
            this.data = data;
            this.next = null;
        }
    }

    static ArrayList<Node> half(Node head){
        if(head == null){
            return null;
        }
        Node slow = head.next;
        Node fast = head.next;
        while(slow != head && fast != head){
            fast = fast.next;
            if(fast.next != head){
                fast = fast.next;
            }
            else {
                break;
            }
            if(fast.next == head){
                break;
            }
            slow = slow.next;
        }
        fast.next = slow.next;
        slow.next = head;
        ArrayList<Node> arr = new ArrayList<>();
        arr.add(head);
        arr.add(fast.next);
        return arr;
    }

    static void print(Node head){
        if (head == null){
            return;
        }
        Node curr = head.next;
        System.out.print(head.data+" ");
        while (curr!=head){
            System.out.print(curr.data+" ");
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args){
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);
        head.next.next.next.next.next = new Node(6);
        head.next.next.next.next.next.next = new Node(7);
        head.next.next.next.next.next.next.next = head;

        ArrayList<Node> arr = half(head);
        for (Node node: arr){
            print(node);
        }

    }
}
