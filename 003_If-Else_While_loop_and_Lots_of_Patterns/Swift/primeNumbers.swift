import Foundation

func checkDivisors(of n: Int) {
    var i = 2

    while i < n {
        if n % i == 0 {
            print("Not prime for \(i)")
        } else {
            print("Prime for \(i)")
        }
        i += 1
    }
}


let n = 10
print("Enter a number: \(n)") // Simulating user input
checkDivisors(of: n)
