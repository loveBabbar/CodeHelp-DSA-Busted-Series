// Binary Search

/* 
- Elements should be in monotonic order
find the middle element
- if the middle element is higher than required element, find in lower section
- if the middle element is lower than required element, find in upper section.
*/



func binarySearch(arr: [Int], key: Int) -> Int {
  var start = 0
  var end = arr.count - 1

  while start <= end {
      let mid = start + (end - start) / 2

      if arr[mid] == key {
          return mid
      } else if key > arr[mid] {
          start = mid + 1
      } else {
          end = mid - 1
      }
  }

  return -1
}

let even = [0, 2, 4, 6, 8]
let odd = [1, 3, 5, 7, 9]

let evenIndex = binarySearch(arr: even, key: 6)
print("Index of 6 is \(evenIndex)")

let oddIndex = binarySearch(arr: odd, key: 14)
print("Index of 7 is \(oddIndex)")

// end
// complexity is O(log n)

// swiftc 012.swift to make executable file
// ./012 to run executable file

