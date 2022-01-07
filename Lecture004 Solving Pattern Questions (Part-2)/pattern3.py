
class solution():
    def pattern(n):
        i=1
        while(i<=n):
            print(f"{i}"*i,end = "")
            print()
            i+=1

if __name__ == '__main__':
    ob=solution
    num = int(input("Enter Number = "))
    ob.pattern(num)