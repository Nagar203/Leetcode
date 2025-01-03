from typing import List

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)
        prefixSum = [0] * (n + 1)

        # Compute the prefix sum where prefixSum[i] holds the sum of elements from nums[0] to nums[i-1]
        for i in range(n):
            prefixSum[i + 1] = prefixSum[i] + nums[i]

        totalSum = prefixSum[n]
        validSplitCount = 0

        # Check each position for a valid split
        for i in range(n - 1):
            if prefixSum[i + 1] >= (totalSum - prefixSum[i + 1]):
                validSplitCount += 1

        return validSplitCount