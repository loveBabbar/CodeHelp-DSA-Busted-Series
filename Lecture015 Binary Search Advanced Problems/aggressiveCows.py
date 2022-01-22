def isPossible(stalls, k, mid, n):

    cowCount = 1
    lastPos = stalls[0]

    for i in range(0,n):

        if(stalls[i]-lastPos >= mid):
            cowCount += 1
            if(cowCount == k):
            
                return True
            
            lastPos = stalls[i]
        
    
    return False


def aggressiveCows(stalls, k):

    stalls.sort()
    s = 0
    n = len(stalls)
    e = stalls[n-1]
    ans = -1
    mid = s + (e-s)/2

    while(s <= e):
        if(isPossible(stalls, k, mid, n)):
            ans = mid
            s = mid + 1
        
        else:
        
            e = mid - 1
        
        mid = s + (e-s)/2
    
    return ans
