#Bubble Sort in python
def BubbleSort(nums:list):
        n = len(nums)
        
        for i in range(n):
                for j in range(0 , n - i - 1):
                        if nums[j] > nums[j + 1]:
                                nums[j] , nums[j + 1] = nums[j + 1] , nums[j]
nums = [12 , 11 , 5 , 9 , 6 , 0]
BubbleSort(nums)
print(nums)
                                