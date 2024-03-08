// Find Pivot Index 

func pivotIndex(_ nums: [Int]) -> Int {
    var sum = 0
    var left = 0
    for item in nums {
        sum += item
    }

    for i in 0..<nums.count {
        if sum-left-nums[i] == left {
            return i
        }
        left+=nums[i]
    }
    return -1
}
let nums = [1,7,3,6,5,6]
print(pivotIndex(nums))


// other method

let pivot = nums.max()
let pivotIndex = nums.firstIndex(of: pivot!)

print(pivotIndex(nums))