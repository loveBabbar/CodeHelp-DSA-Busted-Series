def check(arr):
    size = len(arr)
    count = 0
    for i in range(1,size):
        if arr[i-1] > arr[i]:
            count += 1
    if arr[size-1] > arr[0]:
        count += 1
    if count == 1:
        print("given array is Sorted and rotated")
    else:
        print("given array is not sorted")
    return None


if __name__ == '__main__':
    array = [3,4,1,2]
    check(array)