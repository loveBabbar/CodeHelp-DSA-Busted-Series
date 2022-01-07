
class solution():
    def pattern(n):
        row=1
        while(row<=n):
            col=1
            while(col<=n-row):
                print(" ",end="")
                col+=1
            print("*"*row,end = "")
            print()
            row+=1

if __name__ == '__main__':
    ob = solution
    num = int(input("Enter Number = "))
    ob.pattern(num)