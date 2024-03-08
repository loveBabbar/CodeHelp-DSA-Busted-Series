
import Foundation

func printPattern(rows: Int, columns: Int) {
    for _ in 1...rows {
        for _ in 1...columns {
            print("*", terminator: "")
        }
        print() // Moves to the next line after printing each row
    }
}

// Example usage with predefined values
let rows = 3 // Replace with desired number of rows
let columns = 7 // Replace with desired number of columns
print("Pattern with \(rows) rows and \(columns) columns:")
printPattern(rows: rows, columns: columns)
