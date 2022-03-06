'''

	Time Complexity: O(N^3)
	Space Complexity: O(1)

	Where N is the number of elements in the array.
	
'''

from sys import stdin, stdout, setrecursionlimit

setrecursionlimit(10 ** 7)

def findTriplets(arr, n,K):
    # Set to keep the track of visited triplets.
    visited = set()
    ans = list()
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1, n):
                # If we find a valid triplet.
                if arr[i] + arr[j] + arr[k] == K:
                    triplet = [arr[i], arr[j], arr[k]]
                    # Sorting the triplet track distinct triplets.
                    triplet.sort()
                    triplet = tuple(triplet)
                    if triplet not in visited:
                        visited.add(triplet)

    for i in visited:
        ans.append(list(i))

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
