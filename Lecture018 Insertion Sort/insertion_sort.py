def insertionSort(a):
    # storing the length of the given array or list in a variable.
    n = len(a)

    for i in range(1 , n):
        # current is storing the i-th element of the list and
        # j is pointing to the index before the current index
        current = a[i]
        j = i-1

        # checking j's boundary condition and 
        # while the current elemet is smaller than a[j], keep shifting j
        # at last place the current element to its correct positon
        while j > -1 and current < a[j]:
            a[j + 1] = a[j]
            j = j - 1

        a[j + 1] = current


a = [64, 34, 25, 12, 22, 11, 90]
insertionSort(a)
print("Sorted array : ")
for i in a:
    print(i)
