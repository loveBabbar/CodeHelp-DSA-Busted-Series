def binarySearch(array,size,target):
    start =0
    end = len(array)-1
    while start<=end:
        mid= start+ (end-start)//2
        if target == array[mid]:
            return mid
        elif target <array[mid]:
            end=mid-1
        else:
            start=mid+1
    return -1
