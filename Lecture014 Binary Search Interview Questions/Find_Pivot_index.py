def pivotIndex(nums):
        leftSum = 0
        rightSum = 0
        total = sum(nums)

        for i, element in enumerate(nums):
            rightSum = total - nums[i] - leftSum

            if leftSum == rightSum:
                return i
            else:
                leftSum += nums[i]

        return -1

nums = [1,7,3,6,5,6]
print(pivotIndex(nums))