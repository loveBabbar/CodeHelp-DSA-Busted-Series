# Q3
    # Counting numbers 5 4 3 2 1

def count(n):
    # Base case
    if n==0:
        return ''
    
    # Printing n
    print(n, end=' ')
    return count(n-1)

if __name__ == "__main__":
    n=int(input("Enter Number: "))
    ans = count(n)
    print(ans)
