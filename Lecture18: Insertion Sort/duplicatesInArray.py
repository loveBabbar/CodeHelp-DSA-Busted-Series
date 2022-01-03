
def findDuplicate(arr):

    ans = 0

    # XOR ing all array elements
    for i in range(0,len(arr)):
        ans = ans ^ arr[i]
    

    # XOR[1, n-1]
    for i in range(0, len(arr)):
        ans = ans ^ i
    return ans
