
def printArray( arr, n):
    for i in range(0,n):
        print(arr[i],end=" ")

    print("\n")


def sortOne( arr, n):

    left = 0;right = n-1

    while(left < right):

        while(arr[left] == 0 and left < right) :
            left = left + 1
        

        while(arr[right] == 1 and left < right):
            right = right -1
        

        # agar yha pohoch gye ho, iska matlab
        # arr[left] == 1 and arr[right] == 0
        if(left < right):
            swap(arr,left,right)
            left=left+1
            right=right-1
  

def swap(arr, x, y):
    arr[x], arr[y] = arr[y], arr[x]
    
if __name__ == "__main__":

    arr = [1, 1, 0, 0, 0, 0, 1, 0]

    sortOne(arr, len(arr))
    printArray(arr, len(arr))

