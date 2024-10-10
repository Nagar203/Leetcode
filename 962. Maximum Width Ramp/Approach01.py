from typing import *

class Solution:
    def maxWidthRamp(self, nums):
        maxRampWidth = 0
        indexStack = []

        # First pass: find the indices of decreasing elements
        for i, num in enumerate(nums):
            if not indexStack or num < nums[indexStack[-1]]:
                indexStack.append(i)

        # Second pass: check for the maximum ramp width
        for i in range(len(nums) - 1, maxRampWidth, -1):
            while indexStack and nums[i] >= nums[indexStack[-1]]:
                maxRampWidth = max(maxRampWidth, i - indexStack.pop())

        return maxRampWidth