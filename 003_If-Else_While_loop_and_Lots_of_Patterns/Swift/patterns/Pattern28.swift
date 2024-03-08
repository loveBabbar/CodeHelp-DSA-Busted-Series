
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    for row in 0..<(2 * n) {
        let totalColsInRow = row > n ? (2 * n - row) : row
        let spaces = n - totalColsInRow
        for _ in 0..<spaces {
            print(" ", terminator: "")
        }
        for _ in 0..<totalColsInRow {
            print("* ", terminator: "")
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
