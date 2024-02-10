def floorSqrt(self, x): 
    #Your code here
        lo, hi = 1, x
        ans = -1
        while lo <= hi:
            m = (lo + hi) // 2
            mSq = m*m
            if mSq == x: return m
            elif mSq > x: hi = m - 1
            else:
                lo = m + 1
                ans = m
        return ans