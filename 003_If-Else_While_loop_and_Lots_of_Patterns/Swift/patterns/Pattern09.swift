
import Foundation

func printPattern9(_ n: Int) {
    var odd = 1
    for row in 1...n {
        // Print leading spaces
        for _ in 1..<row {
            print("  ", terminator: "")
        }
        // Print asterisks
        for _ in 1...(2 * n - odd) {
            print("* ", terminator: "")
        }
        odd += 2
        print() // Moves to the next line after printing each row
    }
}

// Example usage with predefined value
let n = 5 // Replace with desired number of rows
print("Pattern with \(n) rows:")
printPattern9(n)
