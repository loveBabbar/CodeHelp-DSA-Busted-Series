# Return true if a number can be represented in the powers of two.

# Since 2^31 is the size limit of the input value (integer),
#     iterate till i == 30
#         compare 'n' with 'ans' by multiplying 'ans' variable * 2 everytime
#             return True if equal
#     else return false after the loop
    
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        ans = 1
        for i in range(31):
            if n == ans:
                return True
            ans *= 2
        return False