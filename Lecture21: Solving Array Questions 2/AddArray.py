def reverse(arr):
    n = len(arr)
    s,e = 0,n-1
    while s <= e:
        arr[s],arr[e] = arr[e],arr[s]
        s+=1;e-=1
    return arr


def add(arr1,arr2):
    i = len(arr1)-1
    j = len(arr2)-1
    arr3 = []
    carry = 0

    while i>=0 and j>=0:
        sum = arr1[i] + arr2[j] + carry
        arr3.append(sum%10)
        carry = sum//10
        i-=1;j-=1
    
    # First case
    while i>=0:
        sum = arr1[i]+carry
        arr3.append(sum%10)
        carry = sum//10
        i-=1

    # Second Case
    while j>=0:
        sum = arr2[j]+carry
        arr3.append(sum%10)
        carry = sum//10

    # Third case
    while carry != 0:
        sum = carry
        arr3.append(sum%10)
        carry = sum//10
    
    arr3 = reverse(arr3)
    return arr3


if __name__ == '__main__':
    list1 = [9,9,9,9,9]
    list2 = [1]
    list3 = add(list1,list2)
    print("Final list is ", list3)
