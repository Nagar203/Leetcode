from typing import *
import collections

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        d = collections.Counter(nums)
        result = []
        for key, val in d.items():
            if(val == 2):
                result.append(key)
        return result