
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    for row in 1...n {
        var ch = Character(UnicodeScalar(60 + n + 4)!)
        for _ in 1...row {
            print("\(ch) ", terminator: "")
            ch = Character(UnicodeScalar(ch.asciiValue! - 1)!)
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
