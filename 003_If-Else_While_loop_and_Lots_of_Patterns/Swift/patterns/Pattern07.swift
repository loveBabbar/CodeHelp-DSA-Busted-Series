
import Foundation

func printPattern7(_ n: Int) {
    for row in 1...n {
        // Print leading spaces
        for _ in 1..<row {
            print("  ", terminator: "")
        }
        // Print asterisks
        for _ in row...n {
            print("* ", terminator: "")
        }
        print() // Moves to the next line after printing each row
    }
}

// Example usage with predefined value
let n = 5 // Replace with desired number of rows
print("Pattern with \(n) rows:")
printPattern7(n)
