from heapq import heappop, heappush
def pairSum(arr,  s):
    ans = []
    for i in range(0,len(arr)):
        for j in range(i+1,len(arr)):
            if(arr[i] + arr[j] == s):
    
                temp = []
                temp.append(min(arr[i], arr[j]))
                temp.append(max(arr[i], arr[j]))
                ans.append(temp)
    # by default uses Quick Sort, 
    # if number of elements is more it uses heap sort 
    # if numverof elements are too small it uses InsertionSort
    heap_sort(ans)
    return ans

#heap sort code
def heap_sort(array):
    heap = []
    for element in array:
        heappush(heap, element)

    ordered = []

    # While we have elements left in the heap
    while heap:
        ordered.append(heappop(heap))

    array = ordered


def partition(input_list, low, high):
    i = (low - 1)
    pivot = input_list[high]
    for j in range(low, high):
        if input_list[j] <= pivot:
            i = i + 1
            input_list[i], input_list[j] = input_list[j], input_list[i]
    input_list[i+1], input_list[high] = input_list[high], input_list[i+1]
    return (i+1)

#quick sort code
def quickSort(input_list, low, high):
    if low < high:
        partition_index = partition(input_list, low, high)
        quickSort(input_list, low, partition_index - 1)
        quickSort(input_list, partition_index + 1, high)


#using insertion sort

def insertionSort( n, arr):
    
    for i in range(1,n):
        temp = arr[i]
        j = i-1
        for j in range(i-1,0,-1):

            if(arr[j] > temp):
                # shift
                arr[j+1] = arr[j]
            
            else:# ruk jao
                break   
        # copy temp value
        arr[j+1] = temp

