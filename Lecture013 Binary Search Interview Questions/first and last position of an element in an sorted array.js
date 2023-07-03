//  As we know in the question it says sorted array and the coplexity is O(log(n)).
// That means we have to use Binary search

// so create two function one is for leftmost index of that element and one is for rightmost index




const upperBound = (arr, key) => {
    let firstIndex = 0
    let start = 0
    let end = arr.length- 1
    while(start <= end){
        let mid = parseInt((start + end)/ 2)

        if(arr[mid] === key){
            firstIndex = mid
            end = mid - 1
        }
        else if(arr[mid] > key){
            end = mid -1
        }
        else{
            start = mid + 1
        }

    }

    return firstIndex
}


const lowerBound = (arr, key) => {
    let lastIndex = 0
    let start = 0
    let end = arr.length - 1
    
    while(start <= end){
        let mid = parseInt((start + end)/ 2)
        if(arr[mid] === key){
            lastIndex = mid
            start = mid + 1
        }
        else if(arr[mid] > key){
            end = mid -1
        }
        else{
            start = mid + 1
        }
    }


    return lastIndex
}


let arr = [0, 0, 2, 2, 2, 2, 2, 3]
let key = 2


console.log("first Index: ", upperBound(arr, key), " last index: ", lowerBound(arr, key))