class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        let pivot = findPivotIndex(nums, 0, nums.count - 1)
        var ans = binarySearch(nums, 0, pivot, target)
        if ans == -1 {
            ans = binarySearch(nums, pivot + 1, nums.count - 1, target)
        }
        return ans
    }
    
    func findPivotIndex(_ nums: [Int], _ low: Int, _ high: Int) -> Int {
        var low = low
        var high = high
        var mid = 0
        
        while low <= high {
            mid = low + (high - low) / 2
            if nums[low] <= nums[high] {
                return high
            } else if nums[mid] > nums[mid + 1] {
                return mid
            } else if nums[mid] < nums[mid - 1] {
                return mid - 1
            } else if nums[mid] > nums[0] {
                low = mid + 1
            } else {
                high = mid - 1
            }
        }
        return mid
    }
    
    func binarySearch(_ nums: [Int], _ low: Int, _ high: Int, _ target: Int) -> Int {
        var low = low
        var high = high
        
        while low <= high {
            let mid = low + (high - low) / 2
            if nums[mid] == target {
                return mid
            } else if nums[mid] > target {
                high = mid - 1
            } else {
                low = mid + 1
            }
        }
        return -1
    }
}

let solution = Solution()
let nums = [4, 5, 6, 7, 0, 1, 2]
let target = 0
let result = solution.search(nums, target)
print("Index of \(target) in \(nums): \(result)")
