
class solution():
    def pattern(n):
        row=1
        while(row<=n):
            col=1
            while(col<=n):
                str=ord('A')+row-1
                print(chr(str),end=" ")
                col+=1
            print()
            row+=1
        # ch="A"
        # print(ord(ch))

            

if __name__ == '__main__':
    ob=solution
    num = int(input("Enter Number = "))
    ob.pattern(num)