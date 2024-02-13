from typing import *

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        check = n/2
        result = 0
        d = {}

        for n in nums:
            if n in d:
                d[n] += 1
            else:
                d[n] = 1
        
        for key, val in d.items():
            if(val > check):
                result = key
        return result