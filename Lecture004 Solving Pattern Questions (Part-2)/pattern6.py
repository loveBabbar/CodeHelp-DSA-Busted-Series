
class solution():
    def pattern(n):
        row=1
        while(row<=n):
            col=row
            while(col>0):
                print(col,end=" ")
                col-=1
            print()
            row+=1

            

if __name__ == '__main__':
    ob=solution
    num = int(input("Enter Number = "))
    ob.pattern(num)