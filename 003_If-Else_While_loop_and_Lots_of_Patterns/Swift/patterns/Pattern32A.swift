
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    for row in 1...n {
        var number = n - row + 1
        for _ in 1...row {
            print("\(number) ", terminator: "")
            number += 1
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
