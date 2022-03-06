class Solution:
    def bitwiseComplement(self, n: int) -> int:
        m = n
        mask = 0
        
        while m != 0:
            mask = (mask << 1) | 1
            m = m >> 1
            
        return ((~n) & mask) if n != 0 else 1