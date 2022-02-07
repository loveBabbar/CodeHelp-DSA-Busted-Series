
def merge(nums1: list[int], m: int, nums2: list[int], n: int) -> None:
    for i in range(n):
        nums1[i+m]=nums2[i]
    nums1.sort()
    return num1

num1=[1,2,3,0,0,0]
m=3
num2=[2,5,6]
n=3

print(merge(num1,m,num2,n))
