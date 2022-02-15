#Implementation OF Binary Search using py3
def binarySearch(arr,start,end,key):
    if start>end:
        return False
    mid=start+(end-start)//2
    if arr[mid]==key:
        return True
    if arr[mid]>key:
        return binarySearch(arr,start,mid-1,key)
    else:
        return binarySearch(arr,mid+1,end,key)
    

arr=[1,2,3,6,70,89,900]
key=70
p=binarySearch(arr,0,len(arr)-1,key)
print(p)
