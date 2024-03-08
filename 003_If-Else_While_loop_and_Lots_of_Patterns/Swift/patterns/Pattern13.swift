
import Foundation

func printPattern13(_ n: Int) {
    var inSpace = -1
    for row in 1...n {
        // Print leading spaces
        for _ in 1...(n - row) {
            print(" ", terminator: "")
        }
        // Calculate total columns and adjust inSpace
        let totalColumns = row == n ? 2 * n - 1 : (row == 1 ? 1 : 2)
        inSpace = row > 2 && row != n ? inSpace + 1 : inSpace

        // Print columns with spaces inside if needed
        for column in 1...totalColumns {
            print("*", terminator: column < totalColumns && row != n ? String(repeating: " ", count: inSpace > 0 ? inSpace : 1) : "")
        }
        print() // Moves to the next line after printing each row
    }
}

// Example usage with predefined value
let n = 5 // Replace with desired number of rows
print("Pattern with \(n) rows:")
printPattern13(n)
