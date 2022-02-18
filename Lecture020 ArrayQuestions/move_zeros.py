


def moveZeroes( nums: list[int]):
    nonZero = 0
    for r in range(len(nums)):
        if nums[r]!=0:
            nums[r], nums[nonZero] = nums[nonZero], nums[r]
            nonZero += 1
    return nums

print(moveZeroes([0,1,0,3,12]))