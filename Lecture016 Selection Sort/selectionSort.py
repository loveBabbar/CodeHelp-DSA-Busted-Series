# function for selection sort
def selectionSort(arr,n):
    for i in range(n):
        min = i
        for j in range(i+1,n):
            if(arr[j]<=arr[min]):
                min = j
        # swapping 
        arr[i],arr[min] = arr[min],arr[i]
    return arr
   

# taking user input 
arr=list(map(int,input().split())) 

# finding length of a list
n = len(arr)
   
# printing the output
print(selectionSort(arr,n))