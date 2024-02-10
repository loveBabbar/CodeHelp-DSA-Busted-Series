import Foundation

func sqrtInteger(_ n: Int) -> Int {
    var s = 0
    var e = n
    var mid = s + (e - s) / 2
    var ans: Int = -1

    while s <= e {
        let square = mid * mid

        if square == n {
            return mid
        }

        if square < n {
            ans = mid
            s = mid + 1
        } else {
            e = mid - 1
        }

        mid = s + (e - s) / 2
    }

    return ans
}

func morePrecision(_ n: Int, _ precision: Int, _ tempSol: Int) -> Double {
    var factor = 1.0
    var ans = Double(tempSol)

    for _ in 0..<precision {
        factor /= 10.0

        var j = ans
        while j * j < Double(n) {
            ans = j
            j += factor
        }
    }

    return ans
}

print("Enter the number: ")
if let input = readLine(), let n = Int(input) {
    let tempSol = sqrtInteger(n)
    print("Answer is:", morePrecision(n, 2, tempSol))
} else {
    print("Invalid input.")
}
