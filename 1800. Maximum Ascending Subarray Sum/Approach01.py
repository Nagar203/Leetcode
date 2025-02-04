from typing import List

class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        currentSum = nums[0]
        maxSum = float('-inf')
        arraySize = len(nums)

        for i in range(1, arraySize):
            if nums[i] > nums[i - 1]:
                currentSum += nums[i]
            else:
                maxSum = max(maxSum, currentSum)
                currentSum = nums[i]

        return max(maxSum, currentSum)