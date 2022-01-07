
class solution():
    def pattern(n):
        row=1
        while(row<=n):
            col,value=1,row
            while(col<=row):
                print(value,end= " ")
                value+=1
                col+=1
            print()
            row+=1

            

if __name__ == '__main__':
    ob=solution
    num = int(input("Enter Number = "))
    ob.pattern(num)