class Solution {
    func splitArray(_ array: [Int], _ key: Int) -> Int {
        func requiredSplit(_ largest: Int) -> Int {
            var currSum = 0
            var splitCount = 0

            for element in array {
                if currSum + element <= largest {
                    currSum += element
                } else {
                    currSum = element
                    splitCount += 1
                }
            }
            return splitCount + 1
        }

        var left = array.max() ?? 0
        var right = array.reduce(0, +)
        var answer = right

        while left <= right {
            let mid = left + (right - left) / 2
            if requiredSplit(mid) <= key {
                answer = mid
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        return answer
    }
}

// Example usage
let arr = readLine()!.split(separator: " ").compactMap { Int($0) }
let m = Int(readLine()!)!
let ob = Solution()
print(ob.splitArray(arr, m))
