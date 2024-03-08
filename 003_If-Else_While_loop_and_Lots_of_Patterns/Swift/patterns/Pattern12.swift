
import Foundation

func printPattern12(_ n: Int) {
    for row in 1...(2 * n) {
        let totalSpaces = row > n ? n - (row - n) : row - 1
        for _ in 1...totalSpaces {
            print("  ", terminator: "")
        }
        let totalColumns = row > n ? row - n : n - row + 1
        for _ in 1...totalColumns {
            print("*   ", terminator: "")
        }
        print() // Moves to the next line after printing each row
    }
}

// Example usage with predefined value
let n = 5 // Replace with desired number of rows
print("Pattern with \(n) rows:")
printPattern12(n)
