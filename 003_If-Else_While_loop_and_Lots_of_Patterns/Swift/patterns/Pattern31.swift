
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    let rcSize = 2 * n - 1
    for row in 1...rcSize {
        for column in 1...rcSize {
            let atEveryIndex = n - min(min(row - 1, column - 1), min(rcSize - row, rcSize - column))
            print("\(atEveryIndex) ", terminator: "")
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
