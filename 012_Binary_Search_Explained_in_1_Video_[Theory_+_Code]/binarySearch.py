def binarySearch(arr, size, key):
  start = 0
  end = size-1
  mid = start + (end-start)//2
  
  while start <= end:
    if arr[mid] == key:
      return mid
    
    if arr[mid] < key:
      start = mid + 1
    else:
      end = mid - 1
      
    mid = start + (end-start)//2
  return -1

if __name__ == '__main__':
  even = [2,4,6,8,12,18]
  odd = [3, 8, 11, 14, 16]
  
  evenIndex = binarySearch(even, 6, 6)
  print("Index of 6 is: ", evenIndex)
  
  oddIndex = binarySearch(odd, 5, 14)
  print("Index of 14 is: ", oddIndex)
