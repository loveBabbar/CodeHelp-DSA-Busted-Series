
import Foundation

func printPattern14(_ n: Int) {
    var inSpace = 2 * n - 5
    for row in 1...n {
        // Print leading spaces
        for _ in 1..<row {
            print(" ", terminator: "")
        }
        // Determine total columns in the current row
        let totalColumns = row == 1 ? 2 * n - 1 : (row == n ? 1 : 2)

        for column in 1...totalColumns {
            print("*", terminator: "")
            if row > 1 && row < n && column == 1 {
                // Print inner spaces for hollow rows
                print(String(repeating: " ", count: inSpace), terminator: "")
                inSpace -= 2
            }
        }
        print() // Moves to the next line after printing each row
    }
}

// Example usage with predefined value
let n = 5 // Replace with desired number of rows
print("Pattern with \(n) rows:")
printPattern14(n)
