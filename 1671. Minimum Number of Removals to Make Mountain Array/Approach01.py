from typing import *

class Solution:
    def minimumMountainRemovals(self, nums):
        leftLIS = self.calculateLIS(nums)
        rightLIS = self.calculateLIS(self.reverseList(nums))[::-1]
        maxMountainSequence = 0

        for i in range(len(nums)):
            if leftLIS[i] > 1 and rightLIS[i] > 1:
                maxMountainSequence = max(maxMountainSequence, leftLIS[i] + rightLIS[i] - 1)

        return len(nums) - maxMountainSequence

    # Helper function for Longest Increasing Subsequence
    def calculateLIS(self, nums):
        tails = []
        lisLengths = []
        for num in nums:
            if not tails or num > tails[-1]:
                tails.append(num)
            else:
                tails[self.findFirstGreaterOrEqual(tails, num)] = num
            lisLengths.append(len(tails))
        return lisLengths

    def findFirstGreaterOrEqual(self, sequence, target):
        low, high = 0, len(sequence)
        while low < high:
            mid = (low + high) // 2
            if sequence[mid] >= target:
                high = mid
            else:
                low = mid + 1
        return low

    def reverseList(self, nums):
        return nums[::-1]