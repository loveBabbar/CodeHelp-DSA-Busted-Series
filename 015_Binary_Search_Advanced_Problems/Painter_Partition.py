class Solution:
    def possible(self, arr, day, m, k):
        count = 0
        bouquet_count = 0

        for i in range(len(arr)):
            if arr[i] <= day:
                count += 1
            else:
                bouquet_count += count // k
                count = 0

        bouquet_count += count // k
        return bouquet_count >= m

    def min_days(self, bloom_day, m, k):
        value = m * k
        if value > len(bloom_day):
            return -1

        minimum = min(bloom_day)
        maximum = max(bloom_day)
        low = minimum
        high = maximum

        while low <= high:
            mid = (low + high) // 2
            if self.possible(bloom_day, mid, m, k):
                high = mid - 1
            else:
                low = mid + 1

        return low


# Example input
bloom_day = [1, 10, 3, 10, 2]
m = 3
k = 1

# Create an instance of the Solution class
solution = Solution()

# Call the min_days method
result = solution.min_days(bloom_day, m, k)

# Print the result
if result == -1:
    print(f"It is not possible to make {m} bouquets with {k} flowers each.")
else:
    print(f"Minimum number of days to make {m} bouquets with {k} flowers each: {result}")
