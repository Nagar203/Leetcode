from typing import *
import collections

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        f = collections.Counter(nums)
        max_val = max([i for i in f.values()])
        result = 0
        for val in f.values():
            if(val == max_val):
                result += val
        return result