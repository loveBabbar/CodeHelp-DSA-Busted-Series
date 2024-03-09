
import Foundation

func printPattern(rows: Int) {
    for row in 1..<rows {
        for _ in 1...row {
            print("*", terminator: "")
        }
        print() // Moves to the next line after printing each row
    }
}

// Example usage with predefined value
let rows = 5 // Replace with desired number of rows
print("Pattern with \(rows) rows:")
printPattern(rows: rows)
