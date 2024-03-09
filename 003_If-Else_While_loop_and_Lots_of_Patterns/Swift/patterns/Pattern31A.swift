
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    let rcSize = 2 * n - 1
    for row in 0...rcSize {
        for column in 0...rcSize {
            let atEveryIndex = min(min(row, column), min(rcSize - row, rcSize - column))
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
