class Solution:
    def splitArray(self, Array: [int], Key: int) -> int:
        def required_split(largest):

            curr_sum  = 0
            split_count = 0

            for Element in Array:
                if curr_sum + Element <= largest:
                    curr_sum += Element
                else:
                    curr_sum = Element
                    split_count += 1
            return split_count + 1

        Left = max(Array)
        Right = sum(Array)
        Answer = Right

        while Left <= Right:
            mid = Left + ((Right-Left)// 2)
            if required_split(mid) <= Key:
                Answer = mid
                Right = mid - 1
            else:
                Left = mid + 1
        return Answer

if __name__=='__main__':     
    arr=[int(x) for x in input().strip().split()]
    m=int(input())        
    ob=Solution()        
    print(ob.splitArray(arr,m))