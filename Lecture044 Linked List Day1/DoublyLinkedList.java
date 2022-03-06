package com.company;

public class DoublyLinkedList {


    public static void main(String[] args) {
        DLLNode head = null;

//        head = insertAtHead(null, 10);

        head = insertAtLast(head, 20);
        head = insertAtLast(head , 30);
        head = insertAtLast(head , 40);
        head =  insertAtLast(head , 50);
        head = insertAtLast(head , 60);

//        head = insertAtLast(head, 76);
        printList(head);

       head = insertAtPosition(head , 5 , 76);
        printList(head);

        head = deleteNode(head , 6);
        printList(head);

    }

    public static DLLNode deleteNode(DLLNode head , int pos){

        //delete 1st Node
        if(pos == 1){
            DLLNode temp = head;

            temp.next.prev = null;
            head =  temp.next;
            temp.next = null;
            return head;
        }

        int count = 1;

        DLLNode curr = head;
        DLLNode prv = null;

        while(count < pos){
            prv = curr;
            curr = curr.next;
            count++;
        }

        //delete at last position
        if(curr.next == null){
            curr.prev = null;
            assert prv != null;
            prv.next = null;

            return head;
        }

        //middle node delete
        curr.prev = null;
//        assert prv != null;
        prv.next = curr.next;
        curr.next.prev = prv;

        curr.next = null;
        return head;

    }

    public static DLLNode insertAtPosition(DLLNode head , int pos , int d){

        int count = 1;
        DLLNode prevNode = head;

        // same condition as insert at head position
        if(pos == 1){
             head = insertAtHead(prevNode , d);
             return head;
        }

        while(count < pos - 1){
            prevNode = prevNode.next;
            count++;
        }

        //case to handle.
        // if we are at last position then insert at tail position.

        if(prevNode.next == null){
            DLLNode temp = insertAtLast(prevNode , d);
            return head;
        }

        //insert at middle position
        DLLNode nodeToInsert = new DLLNode(d); // create the new node with data d.

        nodeToInsert.next = prevNode.next;
        prevNode.next.prev = nodeToInsert;
        prevNode.next = nodeToInsert;
        nodeToInsert.prev = prevNode;

        return head;
    }

    public static int getLength(DLLNode head){
        DLLNode temp = head;
        int count = 0;

        while(temp != null){
            count++;
            temp = temp.next;
        }

        return count;
    }

    public static DLLNode insertAtHead(DLLNode head , int d){

        DLLNode newNode = new DLLNode(d);

        if (head != null) {
            head.prev = newNode;
            newNode.next = head;
        }
        head = newNode;
        return head;
    }

    public static DLLNode insertAtLast(DLLNode head , int d){

        if(head == null){
            return new DLLNode(d);
        }
        DLLNode temp = head;

        while (temp.next != null){
            temp = temp.next;
        }

        DLLNode newNode = new DLLNode(d);
        temp.next = newNode;
        newNode.prev = temp;

            return head;
    }


    public static void printList(DLLNode head) {
        DLLNode temp = head;

        System.out.print("null");

        while (temp != null){
            System.out.print(" <-- " + temp.data + " --> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

}



class DLLNode{
    int data;
    DLLNode prev;
    DLLNode next;

    public DLLNode(int data){
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}
