def power(n):

    #base case 
    if(n == 0) :
        return 1

    #recursive relation
    return 2 * power(n-1)   


if __name__ == "__main__":
    n=int(input())
    ans = power(n)
    print(ans)
