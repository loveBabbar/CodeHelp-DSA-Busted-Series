
def printa(arr, s, e):

    for i in range(s,e+1):
        print(arr[i],end=" ")
    print("\n")


def binarySearch( arr, s, e, k):
    print("\n")
    printa(arr, s, e)

    # base case

    # element not found
    if(s > e):
        return False

    mid = s + (e-s)//2
    print("value of arr mid is ",arr[mid])
    # element found
    if(arr[mid] == k):
        return True

    if(arr[mid] < k):
        return binarySearch(arr, mid+1, e, k)
    
    else:
        return binarySearch(arr, s, mid-1, k)
    



if __name__ == "__main__":

    arr = [2, 4, 6, 10, 14, 18, 22, 38, 49, 55, 222]
    size = 11
    key = 222

    print("Present or not ",binarySearch(arr, 0, size-1, key))


