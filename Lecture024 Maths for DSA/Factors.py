def Factors(num:int):
        for i in range(1 , num):
                if num % i == 0:
                        print(i)
num = 10
Factors(num)