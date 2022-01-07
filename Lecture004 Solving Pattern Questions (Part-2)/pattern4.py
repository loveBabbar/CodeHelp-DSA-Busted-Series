
class solution():
    def pattern(n):
        i=1
        count=2
        while(i<=n):
            j=1
            while(j<i):
                print(count,end=" ")
                j+=1
                count+=1
            count-=1
            print()
            i+=1
            

if __name__ == '__main__':
    ob=solution
    num = int(input("Enter Number = "))
    ob.pattern(num)