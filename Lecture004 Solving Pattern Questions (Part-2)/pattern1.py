class solution():
    def pattern(n):
        i=1
        while(i<=n):
            j=1
            while(j<=n):
                print(n-j+1,end=" ")
                j+=1
            print()
            i+=1

if __name__ == '__main__':
    num = int(input("Enter Number = "))
    ob=solution
    ob.pattern(num)
