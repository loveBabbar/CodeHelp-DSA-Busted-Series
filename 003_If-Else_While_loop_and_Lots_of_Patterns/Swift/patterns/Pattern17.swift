
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    for row in 1..<(2 * n) {
        let totalColumns = row > n ? 2 * n - row : row
        let spaces = n - totalColumns
        for _ in 0..<spaces {
            print("  ", terminator: "")
        }
        for column in stride(from: totalColumns, through: 1, by: -1) {
            print("\(column) ", terminator: "")
        }
        for column in 2...totalColumns {
            print("\(column) ", terminator: "")
        }
        print("")
    }
}

// Taking user input for the number of rows
print("Enter Number of ROWS for the Pattern: ", terminator: "")
if let input = readLine(), let n = Int(input) {
    printPattern(n)
} else {
    print("Invalid input")
}
