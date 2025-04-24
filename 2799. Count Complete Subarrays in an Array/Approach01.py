from typing import List

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        totalDistinctCount = len(set(nums))
        completeCount = 0
        windowDistinct = 0
        frequency = {}
        left = 0

        for current in nums:
            frequency[current] = frequency.get(current, 0) + 1
            if frequency[current] == 1:
                windowDistinct += 1  # new distinct enters window

            # Shrink window from left until missing a distinct
            while windowDistinct == totalDistinctCount:
                leftNum = nums[left]
                frequency[leftNum] -= 1
                left += 1
                if frequency[leftNum] == 0:
                    windowDistinct -= 1

            # All subarrays ending at current index and starting before 'left' are complete
            completeCount += left

        return completeCount