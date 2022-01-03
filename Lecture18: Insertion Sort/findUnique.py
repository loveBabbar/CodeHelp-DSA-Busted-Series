def findUnique(arr, size):

    ans = 0

    for i in range(0,size):
        ans = ans ^ arr[i]
    return ans

