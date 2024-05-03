from typing import *

class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        s = set(nums)
        result = -1
        for v in nums:
            if -v in s:
                result = max(result, v)
        return result
