from typing import *
from collections import *

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        check = n/2
        result = 0

        d = collections.Counter(nums)

        for key, val in d.items():
            if(val > check):
                result = key
        return result