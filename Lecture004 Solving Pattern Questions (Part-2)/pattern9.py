
class solution():
    def pattern(n):
        row=1
        
        while(row<=n):
            col=1
            str=ord('A')+row-1
            while(col<=row):
                print(chr(str),end=" ")
                str+=1
                col+=1
            print()
            row+=1

if __name__ == '__main__':
    ob=solution
    num = int(input("Enter Number = "))
    ob.pattern(num)