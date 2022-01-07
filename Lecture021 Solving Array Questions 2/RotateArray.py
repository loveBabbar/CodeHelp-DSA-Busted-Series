def rotate(arr, k):

    temp=arr.copy()
    size = len(temp)
    for i in range(size):
        temp[(i+k) % size] = arr[i]

    return temp


if __name__ == '__main__':
    array = [11, 7, 3, 12, 4]
    ans = rotate(array,3)
    print("Rotated Array is ",ans)

