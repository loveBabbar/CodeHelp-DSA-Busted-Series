package com.company;

public class CircularLinkedList {
    public static void main(String[] args) {
        CLLNode tail = null;

       tail =  insertNode(null, 5 , 3);
       print(tail);

       tail = insertNode(tail , 3 , 5);
       print(tail);
//
//       tail = insertNode(tail , 5 , 9);
//       print(tail);
//
//       tail = insertNode(tail , 3 , 7);
//        print(tail);

        tail = deleteNode(tail , 5);
        print(tail);

    }

    public static void print(CLLNode tail){

            if(tail == null){
                System.out.println("List is Empty");
                return;
            }
        CLLNode curr = tail;

            do {
                System.out.print(curr.data + " --> ");
                curr = curr.next;
            }
            while (curr != tail);
            System.out.print("First Node (" + tail.data + ")");
            System.out.println();


    }

        public static CLLNode deleteNode(CLLNode tail , int data){
                if(tail == null){
                    System.out.println("List is empty");
                    return null;
                }

                else {
                    CLLNode prev = tail;
                    CLLNode curr = tail.next;


                    while (curr.data != data){
                        prev = curr;
                        curr = curr.next;
                    }

                    if(curr == prev) // single element in list
                    {
                        tail = null;
                        return null;
                    }
                    if(curr == tail){ // deleting tail so point it to prev
                        tail = prev;
                    }

                    prev.next = curr.next;
                    curr.next = null;

                    return tail;
                }
        }
    public static CLLNode insertNode(CLLNode tail , int val , int d){

        CLLNode newNode = new CLLNode(d);
        //empty list
        if(tail == null){
            tail = newNode;
            newNode.next = newNode;
        }
        else {
            CLLNode curr = tail;

            while(curr.data != val){
                curr = curr.next;
            }

            //found element curr -> current value
            newNode.next = curr.next;
            curr.next = newNode;
        }
        return tail;

    }
}

class CLLNode {
    int data;
    CLLNode next;

    public CLLNode(int data){
        this.data =  data;
         this.next = null;
    }
}
