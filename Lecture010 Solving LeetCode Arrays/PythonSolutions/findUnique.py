# When you XOR same number twice, it gives you 0
# Example:
#         binary rep
# [1,      001
#  3,      011
#  4,      100
#  1,      001
#  3,      011
#  ]       ---
#          100     Performing XOR on all elements
# Unique element is returned if present, otherwise 0 

import sys

def findUnique(arr, n) :
    #Your code goes here
    ans = 0
    for i in range(len(arr)):
        ans = ans ^ arr[i]
    
    return ans