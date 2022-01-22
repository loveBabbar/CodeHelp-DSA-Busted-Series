
def isSorted(arr, size):

    # base case
    if(size == 0 or size == 1):
        return True
    

    if(arr[0] > arr[1]):
        return False
    else:
        rem_arr = arr[1:]
        remainingPart = int(isSorted(rem_arr, len(rem_arr)))
        return remainingPart
    



if __name__ == '__main__':

    arr =[2, 3, 9, 9, 9]
    size = 5

    ans = int(isSorted(arr, size))

    if(ans):
        print("Array is sorted ")
    
    else:
        print("Array is not sorted ")
    


