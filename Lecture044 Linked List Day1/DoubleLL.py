class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

class DLL():
    def __init__(self,head=None):
        self.head = head

    def append(self,new_node):
        curr = self.head

        if curr:
            while curr.next:
                curr = curr.next
            curr.next = new_node
            new_node.prev = curr
        else:
            self.head = new_node

    def print(self):
        curr = self.head
        while curr:
            print(curr.value,end="-->")
            curr = curr.next

    def insert(self,data,pos):
        count = 1
        curr = self.head
        if pos ==1:
            data.next = self.head
            self.head.prev = data
            self.head = data
        while curr:
            if count+1 == pos:
                data.next = curr.next
                curr.next.prev = data
                data.prev = curr
                curr.next = data
                return
            else:
                count +=1
                curr = curr.next


    #deleting nodes
    def delelte(self,data):
        curr = self.head

        if curr.value == data:
            curr.next.prev = None
            self.head = curr.next
            curr.next = None

        else:
            while curr:
                if curr.value == data:
                    break
                temp = curr
                curr = curr.next
            if curr == None:
                    return
            curr.prev = None
            temp.next = curr.next
            curr.next = None
            








e1 = Node(1)
e2 = Node(2)
e3 = Node(3)
e4 = Node(4)


l1 = DLL(e1)
l1.append(e2)
l1.append(e3)
l1.append(e4)

print(l1.print())

#e5 = Node(6)

#l1.insert(e5,3)
#print(l1.print())

l1.delelte(4)
print(l1.print())
