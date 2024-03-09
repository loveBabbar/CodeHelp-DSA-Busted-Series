func sumFromOneToN(_ n: Int) -> Int {
    var sum = 0  // Initializes the sum variable to store the result
    for i in 1...n {  
        sum += i  
    }
    return sum 
}

// Example usage of the function
let n = 10
let totalSum = sumFromOneToN(n)
print("The sum from 1 to \(n) is \(totalSum)")
