
import Foundation

func printPascalsTriangle(_ n: Int) {
    for row in 0..<n {
        var c = 1  // The first value in a row is always 1
        for i in 0...row {
            print(c, terminator: " ")
            c = c * (row - i) / (i + 1)  // Update c to the next number in the row
        }
        print()  // Move to the next line after each row
    }
}

// Example usage with predefined value
let n = 5  // Replace with desired number of rows
print("Pascal's Triangle with \(n) rows:")
printPascalsTriangle(n)
