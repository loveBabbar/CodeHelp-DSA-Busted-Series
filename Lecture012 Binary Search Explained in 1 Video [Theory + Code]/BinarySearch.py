def BinarySearch(nums:list , key:int):
        start = 0
        end = len(nums) - 1;
        
        mid = int((start + (end - start) / 2))
        
        while start <= end:
                if nums[mid] == key:
                        return mid
                if key > nums[mid]:
                        start = mid + 1
                else:
                        end = mid - 1
                mid = int(start + (end - start) / 2)
        return -1
even = [2 , 4 , 6 , 8 , 12 , 18] 
odd = [3 , 8 , 11 , 14 , 16]

print("index of 6 is ",BinarySearch(even , 6))
print("index of 14 is ",BinarySearch(odd , 14))        