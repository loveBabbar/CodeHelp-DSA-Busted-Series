
import Foundation

func printPattern5A(_ n: Int) {
    for row in 0..<2*n {
        let totalColsInRow = row > n ? 2 * n - row : row
        for column in 1...totalColsInRow {
            print(column, terminator: " ")
        }
        print() // Moves to the next line after printing each row
    }
}

// Example usage with predefined value
let n = 3 // Replace with desired number of rows for the full pattern
print("Pattern with \(n) rows:")
printPattern5A(n)
