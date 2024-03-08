
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    for row in 1...n {
        for column in 1...row {
            let value = (row + column) % 2 == 0 ? 0 : 1
            print("\(value) ", terminator: "")
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
