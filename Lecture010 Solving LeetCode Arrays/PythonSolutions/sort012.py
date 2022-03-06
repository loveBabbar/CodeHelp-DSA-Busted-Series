'''

	Time Complexity: O(N^2)
	Space Complexity: O(1)

	Where N is the number of elements in the array.
	
'''

from sys import stdin, stdout, setrecursionlimit

def findTriplets(arr, n, k):
    ans = list()
    # Sorting the arraylist.
    arr = sorted(arr)

    i = 0
    while i < n:
        target = k-arr[i]
        front, back = i + 1, n - 1
        while front < back:
            sum = arr[front] + arr[back]
            # Finding answer which starts from arr[i].
            if sum < target:
                front += 1

            elif sum > target:
                back -= 1

            else:
                x, y = arr[front], arr[back]
                ans.append([arr[i], x, y])
                # Incrementing front pointer until we reach a different number.
                while front < back and arr[front] == x:
                    front += 1
                # Decrementing last pointer until we reach a different number.
                while front < back and arr[back] == y:
                    back -= 1
                    
	# Ensuring that we don't encounter duplicate values for arr[i].
        while i + 1 < n and arr[i] == arr[i + 1]:
            i += 1

        i += 1
    return ans



















# Taking input using fast I/0.
def takeInput():
    N = int(stdin.readline())
    arr = list(map(int, stdin.readline().strip().split(" ")))
    K = int(stdin.readline())
    return N, arr,K


tc = int(input())
while tc > 0:
    N, arr,K = takeInput()
    ans = findTriplets(arr, N,K)

    if len(ans) == 0:
        stdout.write("-1\n")

    else:
        for i in ans:
            i.sort()
            stdout.write(str(i[0]) + " " + str(i[1]) + " " + str(i[2]) + "\n")

    tc -= 1
