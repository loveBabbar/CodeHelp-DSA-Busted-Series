def reverse(arr):
    s = 0; e = len(arr)-1
    
    while s < e:
        arr[s],arr[e] = arr[e],arr[s]
        s+=1;e-=1
    
    return arr




if __name__ == '__main__':
    array = [11, 7, 3, 12, 4]
    ans = reverse(array)
    print("Reversed Array is ",ans)