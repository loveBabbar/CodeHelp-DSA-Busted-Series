
def isPrime( n ):

    if(n<=1):
        return False

    for i in range(2,n):
    
        if(n%i==0):
            return False
    return True

if __name__=="__main__":

    n = int(input())

    if(isPrime(n)):
        print("It is a Prime Number")
    
    else:
        print(" It is not a Prime Number")
    