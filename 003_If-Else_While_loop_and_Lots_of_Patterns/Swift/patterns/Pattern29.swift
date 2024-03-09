
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    var inSpaces = 2 * n - 2
    var belowSpaces = 2
    for row in 1...(2 * n - 1) {
        let totalColumns = row > n ? 2 * n - row : row
        for _ in 1...totalColumns {
            print("*", terminator: "")
        }
        let spaces = row <= n ? inSpaces : belowSpaces
        for _ in 1...spaces {
            print(" ", terminator: "")
        }
        row <= n ? (inSpaces -= 2) : (belowSpaces += 2)
        for _ in 1...totalColumns {
            print("*", terminator: "")
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
