class Solution {
    func bubbleSort(_ arr: inout [Int]) -> [Int] {
        let n = arr.count
        for i in 0..<n - 1 {
            var swapped = false
            for j in 0..<n - i - 1 {
                if arr[j] > arr[j + 1] {
                    arr.swapAt(j, j + 1)
                    swapped = true
                }
            }
            if !swapped {
                break
            }
        }
        return arr
    }
}

// Example usage
let solution = Solution()
var exampleArray = [64, 34, 25, 12, 22, 11, 90]
let sortedArray = solution.bubbleSort(&exampleArray)

print("Original array:", exampleArray.map { String($0) }.joined(separator: " "))
print("Sorted array:", sortedArray.map { String($0) }.joined(separator: " "))
