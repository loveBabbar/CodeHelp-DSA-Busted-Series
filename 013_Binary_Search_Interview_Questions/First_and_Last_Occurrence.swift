
var arr: [Int] = [1, 8, 8, 8, 9, 10]

func firstOccurrence(arr: [Int], key: Int) -> Int {

    var start = 0;
    var end = arr.count - 1;
    var mid = start + (end - start) / 2;
    var ans: Int = 0

  while start <= end {
    if(arr[mid] == key){
      ans = mid
      end = mid - 1
    }
    else if(arr[mid] < key){
      start = mid+1
    }
    else{
      end = mid - 1
    }

    mid = start + (end - start)/2


  }
  return ans

}  

func lastOccurrence(arr: [Int], key: Int) -> Int {

    var start = 0;
    var end = arr.count - 1;
    var mid = start + (end - start) / 2;
    var ans: Int = 0

   while start <= end {

        if(arr[mid] == key){
            ans = mid
            start = mid+1
        }
        else if(arr[mid] < key){
            start = mid+1
        }
        else if(arr[mid]>key){
            end = mid - 1
        }
        mid = start + (end - start)/2

  }
  return ans
}

print(firstOccurrence(arr: arr, key: 8))
print(lastOccurrence(arr: arr, key: 8))