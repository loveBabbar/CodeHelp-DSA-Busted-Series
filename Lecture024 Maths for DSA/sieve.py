
#using Sieve
def sieve(prime):

    #setting TRUE for every number
    for i in range(2, 1000001):
        prime.append(1)

    for i in range(2, 1000001):

        if(prime[i]):
            #iske saare multiple mark krde - non prime
            for j in range(2*i, 1000001,i):
                prime[j] = 0
    

if __name__ == '__main__':

    prime = [0,0]
    sieve(prime)

    n = int(input())
    while(n != -1):
        if(prime[n]):
            print("It is a Prime Number")
        else:
            print(" It is not a Prime Number")
        n = int(input())
