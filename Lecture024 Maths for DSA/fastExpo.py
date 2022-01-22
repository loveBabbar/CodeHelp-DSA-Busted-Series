
def fastExpo( a, b):

    res = 1;

    while(b > 0):

        if(b & 1):
            # odd
            res = res*a
        b = b >> 1
        a = a * a
    return res

if __name__ == '__main__':

    
    print("Enter the Values of a and b")
    i = list(map(int, input().split()))
    a, b = i[0], i[1]

    print("Answer is: ",fastExpo(a, b))
