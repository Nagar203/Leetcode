from typing import *
from collections import *

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        check = n/2
        result = 0
        num = set(nums)
        for n in num:
            val = nums.count(n)
            if val > check:
                result = n
            
        return result