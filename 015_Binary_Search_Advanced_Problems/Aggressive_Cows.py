class Solution:
    def is_possible(self, stalls, min_dist, k):
        cows = 1
        last_cow_position = stalls[0]

        for i in range(1, len(stalls)):
            if stalls[i] - last_cow_position >= min_dist:
                cows += 1
                last_cow_position = stalls[i]
                if cows >= k:
                    return True
        return False

    def solve(self, n, k, stalls):
        stalls.sort()
        low, high = 1, stalls[-1] - stalls[0]
        res = 0

        while low <= high:
            mid = (low + high) // 2
            if self.is_possible(stalls, mid, k):
                res = mid
                low = mid + 1
            else:
                high = mid - 1
        return res


# Input handling
t = int(input().strip())

for _ in range(t):
    n, k = map(int, input().strip().split())
    stalls = list(map(int, input().strip().split()))

    obj = Solution()
    result = obj.solve(n, k, stalls)
    print(result)


'''
example input
    2         : t
    5 3       : n ,k
    1 2 8 4 9 : stalls

example output
    3

'''
