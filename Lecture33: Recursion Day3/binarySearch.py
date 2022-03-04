def binary(l,start,end,target):
    mid=(start+end)//2
    if start>end:
        return False
    if l[mid]==target:
        return True

    if l[mid]<target:
        return binary(l,mid+1,end,target)
    else:
        return binary(l,start,mid-1,target)

    return -1  
l=[2,3,5,8,9,12,15]
e=len(l)-1
target=9
print(binary(l,0,e,target))
