
def gcd( a, b):

    if(a == 0):
        return b

    if(b == 0):
        return a

    while(a != b):
        if(a > b):
            a = a-b
    
        else:
            b = b-a
    return a

if __name__ == "__main__":
    
    print("Enter the Values of a and b ")
    i = list(map(int,input().split()))
    a, b = i[0],i[1]

    ans = gcd(a, b)

    print(" The GCD of ",a," & ",b ," is: ",ans)