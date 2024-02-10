func peakIndexInMountainArray(arr: [Int]) -> Int {
   var start = 0
   var end = arr.count - 1
   var mid = start + (end - start) / 2

   while start < end {
       if arr[mid] < arr[mid + 1] {
           start = mid + 1
       } else {
           end = mid
       }
       mid = start + (end - start) / 2
   }
   return start
}

// Example usage
let arr = [1, 2, 3, 4, 5, 4, 3, 2, 1]
let peakIndex = peakIndexInMountainArray(arr: arr)
print("Peak index in the array: \(peakIndex)")