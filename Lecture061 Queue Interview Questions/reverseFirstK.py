from queue import Queue

def modify_queue(q, k):
    

    stack = []
    
    for _ in range(k):
        val = q.get()
        stack.append(val)
    
    while stack:
        val = stack.pop()
        q.put(val)
    
    t = q.qsize() - k
    
    for _ in range(t):
        val = q.get()
        q.put(val)
    
    return q

# Driver code
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    q = Queue()
    elements = list(map(int, input().split()))
    for a in elements:
        q.put(a)
    
    ans = modify_queue(q, k)
    
    while not ans.empty():
        a = ans.get()
        print(a, end=" ")
    print()






# Algorithm:
    # Push the first k elements into a stack and pop them from the queue
    # Pop elements from the stack and push them back into the queue
    # Pop the remaining (n-k) elements from the front of the queue and push them back into the queue
