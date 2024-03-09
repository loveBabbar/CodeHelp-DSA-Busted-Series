
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    for row in 1...n {
        let spaces = n - row
        for _ in 0..<spaces {
            print("  ", terminator: "")
        }
        for column in stride(from: row, through: 1, by: -1) {
            print("\(column) ", terminator: "")
        }
        for column in 2...row {
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
