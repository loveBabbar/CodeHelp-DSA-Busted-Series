
class solution():
    def pattern(n):
        row=1
        while(row<=n):
            # #print 1st triangle
            col=1
            while(col<=(n-row+1)):
                print(col,end=" ")
                col+=1

            #print 2nd triangle (star)
            star=1
            while(star<=(row*2-1)):
                print("*",end=" ")
                star+=1
            
            #print 3rd triangle 
            k=n-row+1
            while(k>0):
                print(k,end=" ")
                k-=1
            print()
            row+=1

           

if __name__ == '__main__':
    ob = solution
    num = int (input("Enter Number = "))
    ob.pattern(num)