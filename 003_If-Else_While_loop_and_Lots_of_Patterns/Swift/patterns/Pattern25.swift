
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    for row in 1...n {
        // Trailing spaces
        for _ in 1...(n - row) {
            print(" ", terminator: "")
        }
        
        var totalColumns = 2
        if row == 1 || row == n {
            totalColumns = n - 1
        }
        for column in 1...totalColumns {
            print("* ", terminator: "")
            if row > 1 && row < n && column == 1 {
                for _ in 1...(n - 3) {
                    print("  ", terminator: "")
                }
            }
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
