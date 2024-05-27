from typing import *
from typing import List

class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()

        if nums[0] >= len(nums):
            return len(nums)

        for i in range(1, len(nums)):
            count = len(nums) - i
            if nums[i - 1] < count and nums[i] >= count:
                return count

        return -1
