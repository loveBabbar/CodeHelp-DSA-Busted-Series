
def getSum( arr, size):

    # base case
    if(size == 0):
        return 0
    
    if(size == 1):
        return arr[0]
    
    rem_arr = arr[1:]
    remainingPart = int(getSum(rem_arr, len(rem_arr)))
    
    sum = arr[0] + remainingPart
    return sum


if __name__ == "__main__":

    arr = [2, 4, 9, 9, 9]
    size = 5

    sum = getSum(arr, size)

    print("Sum is ",sum )



