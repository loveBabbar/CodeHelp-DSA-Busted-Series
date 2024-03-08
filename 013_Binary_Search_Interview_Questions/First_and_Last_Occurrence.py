def firstOcc(arr, n, key):

   start = 0
   end = n - 1
   mid = start + (end - start) // 2
   ans = -1

   while start <= end:
       if arr[mid] == key:
           ans = mid
           end = mid - 1  # search for an earlier occurrence
       elif key > arr[mid]:
           start = mid + 1  # search in the right subarray
       else:
           end = mid - 1  # search in the left subarray
       mid = start + (end - start) // 2

   return ans


def lastOcc(arr, n, key):

   start = 0
   end = n - 1
   mid = start + (end - start) // 2
   ans = -1

   while start <= end:
       if arr[mid] == key:
           ans = mid
           start = mid + 1  # search for a later occurrence
       elif key > arr[mid]:
           start = mid + 1  # search in the right subarray
       else:
           end = mid - 1  # search in the left subarray
       mid = start + (end - start) // 2

   return ans


odd = [1, 2, 3, 7, 7, 7, 7, 8, 9]
print("First occurrence of 7 is", firstOcc(odd, 9, 7))
print("Last occurrence of 7 is", lastOcc(odd, 9, 7))
