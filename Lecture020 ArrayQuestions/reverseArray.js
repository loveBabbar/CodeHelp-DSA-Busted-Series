// reversing the orignal array
function reverseArrayInPlace(arr) {
    let start=0, end=arr.length-1;
    let temp;
    while(start<=end) {
      temp=arr[start];
      arr[start]=arr[end];
      arr[end]=temp;
      start++;
      end--;
    }
    
  }
  // reversing an array without changing the orignal array
  function reverseArray(arr) {
    let result=[];
    result=JSON.parse(JSON.stringify(arr));
    let start=0;
    let end= result.length-1;
    let temp;
    while(start<=end) {
      temp=result[start];
      result[start]=result[end];
      result[end]=temp;
      start++;
      end--;
    }
    console.log("result : " + result);
    console.log("question : " + arr);
    return result;
  }
  
  console.log(reverseArray(["A", "B", "C"]));
  // → ["C", "B", "A"];
  var arrayValue = [1, 2, 3, 4, 5];
  reverseArrayInPlace(arrayValue);
  console.log(arrayValue);
  // → [5, 4, 3, 2, 1]