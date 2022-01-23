package com.company;

public class SinglyLinkedList {
    public static void main(String[] args) {

        Node head = new Node(10);
        Node tail = head;


        tail = insertAtLast(tail , 15);
        tail = insertAtLast(tail , 20);
        tail =  insertAtLast(tail , 25);
        tail = insertAtLast(tail , 35);

        printList(head);

        head = insertAtPosition(head , 6 , 50);
        printList(head);

        head = deleteNode(head , 6);
        printList(head);
    }

    //inserting a node at head Position
    //  Note: We are returning new head as we cannot pass the address like c++;

    public static Node insertAtHead(Node head , int d){
        Node temp = new Node(d);
        temp.next = head;

        head = temp;

        return head;
    }

        //insert New Node at Last
    public static Node insertAtLast(Node tail , int d){

        Node newNode = new Node(d);
        tail.next = newNode;
        tail = newNode;

        return tail;
    }

    //insert at given position
    public static Node insertAtPosition(Node head , int position , int d){
        int count = 1;
        Node prevNode = head;

         // same condition as insert at head position
        if(position == 1){
            return insertAtHead(prevNode , d);
        }


        while(count < position - 1){
            prevNode = prevNode.next;
            count++;
        }

        //case to handle.
        // if we are at last position then insert at tail position
        if(prevNode.next == null){
            Node temp = insertAtLast(prevNode , d);
            return head;
        }

        //insert at middle position
        Node nodeToInsert = new Node(d);
        nodeToInsert.next = prevNode.next;
        prevNode.next = nodeToInsert;

        return head;
    }

    public static Node deleteNode(Node head , int pos){

        //delete 1st Node
        if(pos == 1){
            head =  head.next;
            return head;
        }

        int count = 1;

        Node curr = head;
        Node prev = null;

        while(count < pos){
            prev = curr;
            curr = curr.next;
            count++;
        }

        //delete at last position
        if(curr.next == null){
            assert prev != null;
            prev.next = null;
            return head;
        }

        //middle node delete
        assert prev != null; // may produce null pointer exception
        prev.next = curr.next;
        return head;

    }

     // print the linked list
    public static void printList(Node head){
        Node temp = head;

        while(temp != null){
            System.out.print(temp.data + " --> ");
            temp = temp.next;
        }
        System.out.print("Null");
        System.out.println();
    }
}

//Create Linked List Node.
//Node class has structure of Node
class Node{
    int data; // current node data
    Node next; // next pointer value

    public Node(int data){ // initialize node
        this.data = data;
        this.next = null;
    }
}