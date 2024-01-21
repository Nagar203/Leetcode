from typing import *

class Solution:
    def rob(self, nums: List[int]) -> int:
        first_val = nums[0]
        second_val = 0
        
        for i in range(2, len(nums)+1):
            rob = nums[i-1] + second_val
            skip = first_val
            temp = max(rob, skip)
            second_val = first_val
            first_val = temp

        return first_val