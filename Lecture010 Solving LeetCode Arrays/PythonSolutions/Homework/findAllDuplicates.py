class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        # res = []
        # for i in range(len(nums)):
        #     for j in range(i+1, len(nums)):
        #         if nums[i] == nums[j]:
        #             res.append(nums[i])
        # return res
    
        # hashMap = {}
        # res = []
        # for i in range(len(nums)):
        #     if nums[i] in hashMap:
        #         res.append(nums[i])
        #     hashMap[nums[i]] = True
        # return res
        
        res = []
        for i in range(len(nums)):
            index = abs(nums[i]) - 1
            if nums[index] < 0:
                res.append(index + 1)
            nums[index] = -nums[index]
            
        return res