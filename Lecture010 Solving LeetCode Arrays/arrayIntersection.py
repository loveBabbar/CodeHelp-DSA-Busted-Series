
def findArrayIntersection(arr1,  n, arr2, m):
    
    i = 0; j = 0;ans = []
    while(i < n and j < m):
        if(arr1[i] == arr2[j]):
            ans.append(arr1[i])
            i=i+1
            j=j+1
    
        elif (arr1[i] < arr2[j]):
            i=i+1
        
        else:
            j=j+1

    
    return ans
