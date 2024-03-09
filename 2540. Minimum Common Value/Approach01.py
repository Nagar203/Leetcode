from typing import *
import sys

class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        s1 = set(nums1)
        s2 = set(nums2)
        comman = list(s1.intersection(s2))
        result = sys.maxsize
        for c in comman:
            result = min(c, result)
        return result if(result != sys.maxsize) else -1