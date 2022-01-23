def selectionSort(arr, n):
    for i in range(n-1):
        minIndex = i
        
        for j in range (i+1,n):
            if arr[j] < arr[minIndex]:
                minIndex = j
            
        arr[minIndex] , arr[i]=arr[i] , arr[minIndex]
        
    return arr
  
if __name__ == "__main__":
    n=5 # size of arr
    arr=[5,9,2,4,3] #take input in list 
    
    ans = selectionSort (arr,n)
    print(ans)
