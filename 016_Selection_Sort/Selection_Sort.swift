// https://leetcode.com/problems/sort-an-array/description/


class Solution {
    func sortArray(_ nums: [Int]) -> [Int] {
        var sortedNums = nums
        
        // Selection sort algorithm
        for i in 0..<sortedNums.count - 1 {
            var minIndex = i
            for j in i + 1..<sortedNums.count {
                if sortedNums[j] < sortedNums[minIndex] {
                    minIndex = j
                }
            }
            sortedNums.swapAt(minIndex, i)
        }
        
        return sortedNums
    }
}

// Example usage
let solution = Solution()
let nums = [64, 25, 12, 22, 11]
let sortedNums = solution.sortArray(nums)
print(sortedNums)
