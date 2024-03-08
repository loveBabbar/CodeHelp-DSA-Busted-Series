class Solution {
    func insertionSort(_ arr: inout [Int]) {
        for i in 1..<arr.count {
            let key = arr[i]

            // Move elements of arr[0..i-1] that are greater than key
            // to one position ahead of their current position

            var j = i - 1
            while j >= 0 && key < arr[j] {
                arr[j + 1] = arr[j]
                j -= 1
            }
            arr[j + 1] = key
        }
    }
}

let solution = Solution()
var arr = [12, 11, 13, 5, 6]

// Call the insertionSort method
solution.insertionSort(&arr)

// Print the sorted array
for i in 0..<arr.count {
    print(arr[i], terminator: " ")
}