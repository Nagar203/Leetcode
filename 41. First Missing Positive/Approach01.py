from typing import *
import collections

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        d = collections.Counter(nums)
        i = 0

        for i in range(1,len(d)+2):
            if(d.get(i) == None):
                return i
        
        return -1