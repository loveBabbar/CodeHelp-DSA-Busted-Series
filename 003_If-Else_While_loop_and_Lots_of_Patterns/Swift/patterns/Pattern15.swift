
import Foundation

func printPattern15(_ n: Int) {
    var inSpace = 1
    var inBelowSpace = 2 * n - 5

    for row in 1...(2 * n - 1) {
        let totalColumns = (row != 1 && row != 2 * n - 1) ? 2 : 1
        let totalSpaces = row > n ? row - n : n - row

        for _ in 1...totalSpaces {
            print(" ", terminator: "")
        }

        for column in 1...totalColumns {
            print("*", terminator: "")
            if row > 1 && row <= n {
                print(String(repeating: " ", count: inSpace), terminator: "")
                inSpace += 1
            }
            if row > n {
                print(String(repeating: " ", count: inBelowSpace), terminator: "")
                inBelowSpace -= 1
            }
        }
        print() // Moves to the next line after printing each row
    }
}

// Example usage with predefined value
let n = 5 // Replace with desired number of rows
print("Pattern with \(n) rows:")
printPattern15(n)
