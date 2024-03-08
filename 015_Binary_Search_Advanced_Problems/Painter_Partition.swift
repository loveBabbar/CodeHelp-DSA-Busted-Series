class Solution {

    func possible(_ arr: [Int], _ day : Int , _ m : Int , _  k : Int) -> Bool {
        var count = 0
        var bouquetCount = 0
        for i in 0..<arr.count {
            if (arr[i] <= day) {
                count += 1
            }
            else {
             bouquetCount += (count / k)
             count = 0
            }
        }
        bouquetCount += (count / k)
        return bouquetCount >= m
    }

    
    func minDays(_ bloomDay: [Int], _ m: Int, _ k: Int) -> Int {
        let value : Int = m * k
        if(value > bloomDay.count) {
            return -1
        }
        let minimum = bloomDay.min() 
        let maximum = bloomDay.max()
        var low = minimum!
        var high = maximum!

        while( low <= high) {
            let mid = (low + high) / 2;
            if (possible(bloomDay,mid,m,k)) {
                high = mid - 1
            }
            else {
                low = mid + 1
            }
        }
        return low

    }
}


let solution = Solution()
// Example input
let bloomDay = [1, 10, 3, 10, 2]
let m = 3
let k = 1

// Call the minDays method
let result = solution.minDays(bloomDay, m, k)

// Print the result
if result == -1 {
    print("It is not possible to make \(m) bouquets with \(k) flowers each.")
} else {
    print("Minimum number of days to make \(m) bouquets with \(k) flowers each: \(result)")
}
