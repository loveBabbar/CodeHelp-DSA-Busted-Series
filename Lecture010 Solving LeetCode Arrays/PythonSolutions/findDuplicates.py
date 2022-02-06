def findDuplicate(arr):
    # Write your code here
#     count = {}
#     for i in arr:
#         if i in count:
#             return i
#         count[i] = 1 + count.get(i, 0)
        
    ans = 0
    for i in range(len(arr)):
        ans = ans^arr[i]
    for i in range(len(arr)):
        ans = ans ^ i
    return ans
