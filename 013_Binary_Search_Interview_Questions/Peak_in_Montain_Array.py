from ast import List

def peakIndexInMountainArray(arr: int) -> int:
    start = 0
    end = len(arr) - 1

    while start < end:
        mid = start + (end - start) // 2

        if arr[mid] < arr[mid + 1]:
            start = mid + 1
        else:
            end = mid

    return start

# Example usage
arr = [1, 2, 3, 4, 5, 4, 3, 2, 1]
peak_index = peakIndexInMountainArray(arr)
print("Peak index in the array:", peak_index)