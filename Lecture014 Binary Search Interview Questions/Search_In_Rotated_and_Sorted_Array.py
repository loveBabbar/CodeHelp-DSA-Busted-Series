class Solution:
    def search(self, nums: [int], target: int) -> int:
        pivot = self.find_pivot_index(nums, 0, len(nums) - 1)
        ans = self.binary_search(nums, 0, pivot, target)

        if ans == -1:
            ans = self.binary_search(nums, pivot + 1, len(nums) - 1, target)
        return ans

    def find_pivot_index(self, nums, low, high):
        mid = 0
        while low <= high:
            mid = low + (high - low) // 2

            if nums[low] <= nums[high]:
                return high
            elif nums[mid] > nums[mid + 1]:
                return mid
            elif nums[mid] < nums[mid - 1]:
                return mid - 1
            elif nums[mid] > nums[0]:
                low = mid + 1
            else:
                high = mid - 1
        return mid

    def binary_search(self, nums, low, high, target):
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                high = mid - 1
            else:
                low = mid + 1
        return -1


if __name__ == "__main__":
    solution = Solution()
    nums = [4, 5, 6, 7, 0, 1, 2]
    target = 0
    result = solution.search(nums, target)
    print(f"Index of {target} in {nums}: {result}")
