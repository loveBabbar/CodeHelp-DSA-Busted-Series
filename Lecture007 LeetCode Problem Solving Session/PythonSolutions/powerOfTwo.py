class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        ans = 1
        for i in range(31):
            if n == ans:
                return True
            ans *= 2
        return False