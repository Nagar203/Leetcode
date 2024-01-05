from typing import *
from bisect import bisect_left

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        result = []

        for i in range(n):
            index = bisect_left(result, nums[i])

            if index == len(result):
                result.append(nums[i])
            else:
                result[index] = nums[i]

        return len(result)