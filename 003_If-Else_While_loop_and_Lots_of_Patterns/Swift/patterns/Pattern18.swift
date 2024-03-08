
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    var inSpaces = 2
    var belowSpaces = 2 * n - 2
    for row in 1...(2 * n) {
        let totalColumns = row > n ? row - n : n - row + 1
        for _ in 1...totalColumns {
            print("*", terminator: "")
        }
        if row <= n && row != 1 {
            for _ in 1...inSpaces {
                print(" ", terminator: "")
            }
            inSpaces += 2
        }
        if row > n && row != 2 * n {
            for _ in 1...belowSpaces {
                print(" ", terminator: "")
            }
            belowSpaces -= 2
        }
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
