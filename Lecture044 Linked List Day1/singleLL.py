class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        
class LinkedList:
    def __init__(self, head=None):
        self.head = head
        
    def append(self, new_node):
        current = self.head
        if current:
            while current.next:
                current = current.next
            current.next = new_node
        else:
            self.head = new_node
            
   
    def print(self):
        current = self.head
        while current:
            print(current.value,end="-->")
            current = current.next
    
    def insert(self, new_element, position):
        count=1
        current = self.head
        if position == 1:
            new_element.next = self.head
            self.head = new_element
        while current:
            if count+1 == position:
                new_element.next =current.next
                current.next = new_element
                return
            else:
                count+=1
                current = current.next

        pass
    
    
    def delete(self, value):
        current = self.head
        if current.value == value:
            self.head = current.next
        else:
            while current:
                if current.value == value:
                    break
                temp = current
                current = current.next
            if current == None:
                return
            temp.next = current.next
            current = None
        

e1 = Node(1)
e2 = Node(2)
e3 = Node(3)
e4 = Node(4)

ll = LinkedList(e1)


ll.append(e2)
ll.append(e3)
print("print 3",ll.head.next.next.value)
ll.insert(e4,3)

ll.delete(4)
print(ll.print())