// "static void main" must be defined in a public class.
public class Main {
    static class Node{
  int data;
  Node next;
  
  Node(int data){
    this.data = data;
    this.next = null;
  }
}

public static void print(Node tail){
    if(tail==null) return;
    
    Node head = tail.next;
    
    Node temp = head;
    
    System.out.println();
    
  do{
      System.out.print(temp.data+" ");
      temp = temp.next;
  }while(temp!=head);
}

public static Node insertAtHead(Node tail,int data){
    Node newNode = new Node(data);
    
    if(tail==null){
        newNode.next = newNode;
        return newNode;
    }
    
    Node head = tail.next;
    
    newNode.next = head;
    
    tail.next = newNode;
    
    head = newNode;
    
    return tail;
}

public static Node insertAtTail(Node tail,int data){
    Node newNode = new Node(data);
    
    if(tail==null){
        newNode.next = newNode;
        return newNode;
    }
    
    Node head = tail.next;
    
    tail.next = newNode;
    
    newNode.next = head;
    
    tail = newNode;
    
    return tail;
    
}

public static Node insertAtPosition(Node tail,int pos,int value){
    
    if(pos==1){
        tail = insertAtHead(tail,value);
        
        return tail;
    }
    
//   if pos > no. of nodes insert at last
    if(pos>getLength(tail)){
        
        tail = insertAtTail(tail,value);
        
        return tail;
    }
    if(tail==null){
        Node newNode = new Node(value);
        tail = newNode;
        newNode.next = newNode;
    }
    
    else{
        int count = 1;
        
        Node curr = tail.next;
        
        while(count<pos-1){
            curr = curr.next;
            count++;
        }
        
        Node newNode= new Node(value);
        
        newNode.next = curr.next;
        
        curr.next = newNode;
    }
    
    return tail;
}

public static Node deleteNode(int pos,Node tail){
    
    if(pos==1){
        tail.next = tail.next.next;
        return tail;
    }
    
//     if pos of node to be deleted > no. of nodes return
    if(pos>getLength(tail)) return tail;
    
    int i = 1;
    
    if(tail==null) return tail;
    
    Node curr = tail.next;
    
    while(i<pos-1){
        
        curr = curr.next;
        
        i++;
    }
    
    Node deleted = curr.next;
    
    if(deleted==tail){
        tail = null;
        return tail;
    }
    curr.next = deleted.next;
    
    return tail;
}

public static int getLength(Node tail){
    
    Node head = tail.next;
    
    int len = 1;
    
    while(head!=tail){
        head = head.next;
        len++;
    }
    
    return len;
}
public static void main(String[] args) {
    
    Node tail = insertAtHead(null,10);
    
    insertAtHead(tail,13);
    insertAtHead(tail,14);

    print(tail);

    tail = insertAtTail(tail, 100);
    tail = insertAtTail(tail, 103);
    print(tail);
  
    tail = insertAtPosition(tail, 6, 22);
    tail = insertAtPosition(tail, 1, 345);
    print(tail);    

    deleteNode(1, tail);
        print(tail);

    deleteNode(7, tail);
        print(tail);

    deleteNode(3, tail);
    print(tail);

}
}
