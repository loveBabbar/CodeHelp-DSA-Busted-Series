import Foundation

class Solution {
    
    func isPossible(stalls: [Int], minDist: Int, k: Int) -> Bool {
        var cows = 1
        var lastCowPosition = stalls[0]
        
        for i in 1..<stalls.count {
            if stalls[i] - lastCowPosition >= minDist {
                cows += 1
                lastCowPosition = stalls[i]
                if cows >= k {
                    return true
                }
            }
        }
        return false
    }

    func solve(n: Int, k: Int, stalls: [Int]) -> Int {
        let sortedStalls = stalls.sorted()
        var low = 1
        var high = sortedStalls.last! - sortedStalls.first!
        var res = 0
        
        while low <= high {
            let mid = (low + high) / 2
            if isPossible(stalls: sortedStalls, minDist: mid, k: k) {
                res = mid
                low = mid + 1
            } else {
                high = mid - 1
            }
        }
        return res
    }
}

// Input
let t = 1
let n = 5
let k = 3
let stalls = [1, 2, 8, 4, 9]

let solution = Solution()
let result = solution.solve(n: n, k: k, stalls: stalls)
print(result)
