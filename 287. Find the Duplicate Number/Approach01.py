from typing import *

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        d = collections.Counter(nums)
        for key, val in d.items():
            if(val>1):
                return key
        return -1