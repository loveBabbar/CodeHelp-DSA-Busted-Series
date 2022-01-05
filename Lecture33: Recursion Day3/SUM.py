def totalSum(l,s):
    if s==0:
        return 0
    if s==1:
        return l[0]
    else:
        total=totalSum(l[1:],s-1)
        return l[0]+ total
        
l=[7,8,2,3]
s=len(l)
print(totalSum(l,s))
