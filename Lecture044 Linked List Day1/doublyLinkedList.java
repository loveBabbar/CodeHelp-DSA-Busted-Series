package Lec44_LinkedList;

public class DLL {
    Node head , tail = null;

    class Node{
        int data;
        Node prev;
        Node next;


        Node(int data){
            this.data = data;
            this.next = null;
            this.prev = null;

        }
    }
    void print(){
        Node temp = head;
        if(head == null){
            System.out.println("List is empty");
            return;
        }
        while (temp != null){
            System.out.print(temp.data+"->");
            temp = temp.next;
        }
        System.out.println("null");
        System.out.println("Head : "+head.data);
        System.out.println("Tail : "+tail.data);
        System.out.println();

    }
    public int getLength(){
        int len = 0;
        Node temp = head;
        while (temp != null){
           len++;
            temp = temp.next;
        }
        return len;
    }

    void addFirst(int data){
        Node temp = new Node(data);
        if(head == null){
            head = tail = temp;
            return;
        }
        head.prev = temp;
        temp.next = head;
        head = temp;
    }

    void addLast(int data){
        Node temp = new Node(data);

        if(head == null){
            head = tail = temp;
            return;
        }
/*      Node curr = head;
            while(curr.next != null){
            curr = curr.next;
            }
        curr.next = temp;
        temp.prev = curr;
*/
        tail.next = temp;
        temp.prev = tail;
        tail = temp;

    }

    void addAtPos(int pos, int data){
        //if pos == 1
        if(pos == 1){
            addFirst(data);
            return;
        }

        Node temp = head;
        int count = 1;
        while (count < pos-1){
          temp = temp.next;
          count++;
        }

        //at last
        if(temp.next == null){
            addLast(data);
            return;
        }
        Node nodeToInsert = new Node(data);

        nodeToInsert.next = temp.next;
        nodeToInsert.prev = temp;
        temp.next = nodeToInsert;
        (nodeToInsert.next).prev = nodeToInsert;

    }

    void deleteNode(int pos){

        if(pos == 1){
            Node temp = head;
            temp.next.prev = null;
            head = temp.next;
            temp.next = null;
        }
        else{
            Node curr = head;
            Node prev = null;
            int count = 1;
            while (count < pos){
                prev = curr;
                curr = curr.next;
                count++;
            }
            if(curr.next == null)
                tail = prev;
            curr.prev = null;
            prev.next = curr.next;
            curr.next = null;

        }
    }

    public static void main(String[] args) {
        DLL list = new DLL();
      System.out.println("Length : "+list.getLength());
        list.addFirst(10);
        list.print();

        list.addFirst(11);
        list.print();

        list.addLast(20);
        list.print();

        list.addAtPos(2,100);
        list.print();

        list.deleteNode(4);
        list.print();


    }
}
