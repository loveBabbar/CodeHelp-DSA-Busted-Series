'''

    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where 'N' is the size of the array.

'''

def pairSum(arr, s):
    n = len(arr)

    # Used to store result.
    ans = []
    
    # Checking sum for every element.
    for i in range(n):
        
        for j in range(i + 1, n):
            
            if (arr[i] + arr[j] == s):
                pair = [-1 for i in range(2)]
                pair[0] = arr[i]
                pair[1] = arr[j]
                ans.append(pair)

    # Used to store final sorted result.
    res = [[-1 for j in range(2)] for i in range(len(ans))]
    for i in range(len(ans)):
        a = ans[i][0]
        b = ans[i][1]
        res[i][0] = min(a, b)
        res[i][1] = max(a, b)

    res = sorted(res, key=lambda x: x[0])

    return res
