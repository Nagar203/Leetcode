class Solution:
    def smallestDistancePair(self, nums, k):
        nums.sort()

        left = 0
        right = nums[-1] - nums[0]

        # Binary search for the smallest distance
        while left < right:
            middle = (left + right) // 2
            if self.countPairsWithDistanceNoGreaterThan(nums, middle) >= k:
                right = middle
            else:
                left = middle + 1

        return left

    # Function to count pairs with distance no greater than maxDistance
    def countPairsWithDistanceNoGreaterThan(self, nums, maxDistance):
        pairCount = 0
        j = 1

        # For each index i, find the first index j such that nums[j] > nums[i] + maxDistance
        for i in range(len(nums)):
            while j < len(nums) and nums[j] <= nums[i] + maxDistance:
                j += 1
            pairCount += j - i - 1

        return pairCount