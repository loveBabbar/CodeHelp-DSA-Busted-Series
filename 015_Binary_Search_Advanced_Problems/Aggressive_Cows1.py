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
        sorted_stalls = sorted(stalls)
        low, high = 1, sorted_stalls[-1] - sorted_stalls[0]
        res = 0

        while low <= high:
            mid = (low + high) // 2
            if self.is_possible(stalls=sorted_stalls, min_dist=mid, k=k):
                res = mid
                low = mid + 1
            else:
                high = mid - 1
        return res


# Input
t = 1
n = 5
k = 3
stalls = [1, 2, 8, 4, 9]

solution = Solution()
result = solution.solve(n=n, k=k, stalls=stalls)
print(result)
