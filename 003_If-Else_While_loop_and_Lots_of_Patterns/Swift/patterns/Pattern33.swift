
import Foundation

// Function to print the specified pattern
func printPattern(_ n: Int) {
    var ch = 65
    for row in 1...n {
        for _ in 1...row {
            if ch % 2 == 0 {
                print(Character(UnicodeScalar(ch)!), terminator: " ")
            } else {
                print(Character(UnicodeScalar(ch + 32)!), terminator: " ")
            }
            ch += 1
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
