
import Foundation

func printPattern(_ n: Int) {
    for row in 0..<2*n {
        let totalColsInRow = row > n ? 2 * n - row : row
        for _ in 0..<totalColsInRow {
            print("*", terminator: " ")
        }
        print() // Moves to the next line after printing each row
    }
}

// Example usage with predefined value
let n = 3 // Replace with desired number of rows for the full pattern
print("Pattern with \(n) rows:")
printPattern(n)
