from typing import *

class Solution:
    def rob(self, nums: List[int]) -> int:
        t = [-1]*101
        t[0] = 0
        t[1] = nums[0]
        n = len(nums)

        for i in range(2, len(nums)+1):
            rob = nums[i-1] + t[i-2]
            skip = t[i-1]
            t[i] = max(rob, skip)

        return t[n]