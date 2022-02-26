
def printArray( arr, n):
    print("Size of array is ",n)
    for i in range(n):
        print(arr[i],end=" ")
    print("\n")


def linearSearch( arr, size, k):
    printArray(arr, size)
    # base case
    if(size == 0):
        return False

    if(arr[0] == k):
        return True
    
    else:
        rem_arr = arr[1:]
        remainingPart = int(linearSearch(rem_arr,len(rem_arr),k))
        return remainingPart
    


if __name__ == "__main__":

    arr = [3, 5, 1, 2, 6]
    size = 5
    key = 6
    ans = int(linearSearch(arr, len(arr), key))

    if(ans):
        print("Present ")
    
    else:
        print("absent ")
    


