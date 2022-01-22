
def printArray( arr, n):

    for i in range(0,n):
        print(arr[i],end=" ")


def swapAlternate( arr, size):

    for i in range(0,size,2):
        if(i+1 < size):
            swap(arr,i, i+1)
    

def swap(arr,x, y):
    arr[x], arr[y] = arr[y], arr[x]


if __name__ == "__main__":

    even = [5, 2, 9, 4, 7, 6, 1, 0]
    odd = [11, 33, 9, 76, 43]

    swapAlternate(even, len(even))
    printArray(even, len(even))

    print("\n")

    swapAlternate(odd, len(odd))
    printArray(odd, len(odd))
