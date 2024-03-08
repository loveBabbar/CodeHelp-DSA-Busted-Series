// Simple Swapping
func reverseEntireList(_ array: inout [Int]) {
    var start = 0 // Initialize 'start' index to the beginning of the array
    var end = array.count - 1 // Initialize 'end' index to the end of the array
    
    // Loop until 'start' index is less than 'end' index
    while start < end {
        array.swapAt(start, end)
        start += 1 // Move 'start' index towards the center
        end -= 1 // Move 'end' index towards the center
    }
}

// Main driver code
var array = [1, 2, 3, 4, 5, 6] // Original array
print("Simple original example array is:", array)
// Call 'reverseEntireList' to reverse the entire array
reverseEntireList(&array)

// Print the result after reversal
print("Reversed of simple array is:", array)

// Using Stack

func reverseArrayUsingStack(_ arr: [Int]) -> [Int] {
    var stack = [Int]() // Initialize an empty stack
    var reversedArr = [Int]() // Initialize an empty array for the reversed elements

    // Push all elements of the input array onto the stack
    for element in arr {
        stack.append(element) // Push element onto stack
    }

    // Pop all elements from the stack to form the reversed array
    while !stack.isEmpty {
        if let topElement = stack.popLast() { // Pop the top element from the stack
            reversedArr.append(topElement) // Append the popped element to the reversed array
        }
    }

    return reversedArr 
}

// Main driver code
let originalArray = [1, 2, 3, 4, 5]
print("Stack Original array:", originalArray)

// Call 'reverseArrayUsingStack' to reverse the array and get a new reversed array
let reversedArray = reverseArrayUsingStack(originalArray)

// Print the reversed array
print("Stack Reversed array using stack:", reversedArray)

