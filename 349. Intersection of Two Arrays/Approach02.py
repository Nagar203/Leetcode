from typing import *

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s3 = set()
        for n1 in nums1:
            if(n1 in nums2):
                s3.add(n1)
        return list(s3)