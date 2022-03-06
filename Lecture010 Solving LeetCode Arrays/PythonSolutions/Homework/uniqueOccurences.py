class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        count = {} 
        for i in arr:
            count[i] = 1 + count.get(i, 0)
       
        # return len(count.values()) == len(set(count.values()))
        ## or, if interviewer doesn't allow the use of set function
        
        values = {}
        for val in count.values():
            if val in values:
                return False
            values[val] = 1 + values.get(val, 0)
        return True