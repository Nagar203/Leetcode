from typing import *

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        total = 0
        result = 0
        
        for i in range(n):
            if(nums[i] < total):
                result = total + nums[i]
            total += nums[i]
        
        if(result == 0):
            return -1
        return result